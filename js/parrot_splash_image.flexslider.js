/* custom code */
(function($) {

  /**
   * Resize delay to account for hidden items
   */
  Drupal.behaviors.flexsliderResize = {
    attach: function(context, settings) {
      $(window).bind('resize', function() {
        setTimeout(function(){
          $('.flexslider', context).data('flexslider').resize();
        },3000);
      }); 
    }
  };

  /**
   * Hook into Flexslider events
   */
  Drupal.behaviors.flexsliderHooks = {
    attach: function(context, settings) {
      var splashSlider = $('.view-media-asset-splash .flexslider', context);       
        
      // Event: Start
      splashSlider.bind('start', function() {
        var slider = $(this).data('flexslider');

        // Slider contains video?
        if (slider.slides.find('video').size() > 0) {
          var allVideos = slider.slides.find('video'),
            currentVideo = slider.slides.eq(slider.currentSlide).find('video');
          
          allVideos.trigger('pause');  
          slider.flexslider("stop");
          slider.addClass('flexslider-has-videos');

          // Kill on mobile as performance is poor
          if (/Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent)) {
            allVideos.remove();
            slider.addClass('mobile-slider').removeClass('flexslider-has-videos');
            slider.find('.slide-has-video').removeClass('slide-has-video');
            slider.flexslider("play");
          }
          else {
            // Pause all videos then play any in current slide
            currentVideo.trigger('play');
            currentVideo.bind('ended',function(){
              if (slider.slides.size() > 1) {
                slider.flexslider("next");
              }
              else {
                currentVideo.trigger('play');
              }
            });
          }
        }
        
        // Shift heights on slide change
        $(window).bind('resize', function () {
          Drupal.flexsliderFlexiHeight(slider);
        });

        $(window).trigger('resize');
      });
      
      // Event: Before
      splashSlider.bind('before', function() {
        var slider = $(this).data('flexslider');
        
        if (slider.hasClass('flexslider-has-videos')) {
          var currentVideo = slider.slides.eq(slider.currentSlide).find('video') || null,
              nextVideo = slider.slides.eq(slider.animatingTo).find('video') || null;
 
          // Pause current slide video, start next slide video
          currentVideo.trigger('pause');
          slider.flexslider("pause");
          
          if (nextVideo.size() > 0) { 
            nextVideo.get(0).currentTime = 0;
            nextVideo.trigger('play');
            nextVideo.bind('ended',function(){
              if (slider.slides.size() > 1) {
                slider.flexslider("next");
              }
              else {
                nextVideo.trigger('play');
              }
            });
          }
          else {
            slider.flexslider("play");
          }
        }
        
        $(window).trigger('resize');
      });
    }
  };

  /**
   * Allow each slide to suggest it's ideal height [data-ideal-height]
   */
  Drupal.flexsliderFlexiHeight = function (slider) {
    var idealHeightEl = slider.slides.eq(slider.animatingTo).find('[data-ideal-height]') || null;

    if (idealHeightEl.size() > 0 && idealHeightEl.data('ideal-height') !== null) {
      idealHeight = idealHeightEl.data('ideal-height');
      slider.find('.slide').css('min-height', idealHeight);
    }
  };   
  
}(jQuery));
