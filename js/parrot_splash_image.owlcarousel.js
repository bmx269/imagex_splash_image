/* custom code */
(function($) {

  /**
   * Hook into owlcarousel events
   */
  Drupal.behaviors.owlcarouselHooks = {
    attach: function(context, settings) {
      var splashSlider = $('.view-media-asset-splash .owl-carousel', context),
        splashSliderOwl = splashSlider.data('owlCarousel') || {};
      
      // Event: BeforeMove
      parrotSplashImageOwlAfterInit = function(owl) {        
        var sliderData = owl.data('owlCarousel'),
          slider = sliderData.$elem,
          slides = sliderData.$owlItems;

        // Slider contains video?
        if (slides.find('video').size() > 0) {
          var allVideos = slides.find('video'),
            currentVideo = slides.eq(sliderData.owl.currentItem).find('video') || null;

          allVideos.trigger('pause');  
          sliderData.stop();
          slider.addClass('slider-has-videos');

          // Kill on mobile as performance is poor
          if (/Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent)) {
            allVideos.remove();
            slider.addClass('mobile-slider').removeClass('slider-has-videos');
            slider.find('.slide-has-video').removeClass('slide-has-video');
            sliderData.play();
          }
          else {
            // Pause all videos then play any in current slide
            currentVideo.trigger('play');
            currentVideo.bind('ended',function(){
              if (slides.size() > 1) {
                sliderData.next();
              }
              else {
                currentVideo.trigger('play');
              }
            });
          }
        }
        
        // Shift heights on slide change
        $(window).bind('resize', function () {
          Drupal.owlcarouselFlexiHeight(sliderData);
        });

        $(window).trigger('resize');
      };
      
      // Event: Before
      parrotSplashImageOwlBeforeMove = function(owl) {
        var sliderData = owl.data('owlCarousel'),
          slider = sliderData.$elem,
          slides = sliderData.$owlItems;
        
        if (slider.hasClass('slider-has-videos')) {
          var currentVideo = slides.eq(sliderData.owl.prevItem).find('video') || null,
              nextVideo = slides.eq(sliderData.owl.currentItem).find('video') || null;
 
          // Pause current slide video, start next slide video
          currentVideo.trigger('pause');
          sliderData.stop();
          
          if (nextVideo.size() > 0) { 
            nextVideo.get(0).currentTime = 0;
            nextVideo.trigger('play');
            nextVideo.bind('ended',function(){
              if (slides.size() > 1) {
                sliderData.next();
              }
              else {
                nextVideo.trigger('play');
              }
            });
          }
          else {
            sliderData.play();
          }
        }
        
        $(window).trigger('resize');
      };
      
      if (typeof splashSliderOwl !== undefined) {
        splashSliderOwl.options.afterInit = parrotSplashImageOwlAfterInit;
        splashSliderOwl.options.beforeMove = parrotSplashImageOwlBeforeMove;
        splashSliderOwl.reinit(splashSliderOwl.options)
      }
    }
  };

  /**
   * Allow each slide to suggest it's ideal height [data-ideal-height]
   */
  Drupal.owlcarouselFlexiHeight = function (slider) {
    var idealHeightEl = slider.$owlItems.eq(slider.owl.currentItem).find('[data-ideal-height]') || null;
    
    if (idealHeightEl.size() > 0 && idealHeightEl.data('ideal-height') !== null) {
      idealHeight = idealHeightEl.data('ideal-height');
      slider.$owlItems.find('.slide').css('min-height', idealHeight);
    }
  };   
  
}(jQuery));
