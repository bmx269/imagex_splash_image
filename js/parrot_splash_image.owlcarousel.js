/* custom code */
(function($) {
  var singleVideoMaxLoops = 2; // play count = +1 for initial play
  
  /**
   * Hook into owlcarousel events
   */
  Drupal.behaviors.owlcarouselHooks = {
    attach: function(context, settings) {
      var splashSliderWrapper = $('.view-media-asset-splash', context),
        splashSlider = $('.view-media-asset-splash .owl-carousel', context),
        splashSliderOwl = splashSlider.data('owlCarousel') || null,
        videoPlay = function(video) {
          if (video !== null && video.size() > 0) {
            var videoElement = video.get(0);
            
            if (videoElement.currentTime > 0) {
              video.trigger('play');
            }
            else {
              videoElement.currentTime = 0;
              video.parent('.slide').addClass('video-loading');
              video.on('canplay', function (event) {
                video.parent('.slide').removeClass('video-loading');
                $(this).trigger('play');
                $(this).off('canplay');
              });
            }
            return true;
          }
          return false;
        },
        videoEnded = function(video, sliderData, slider, slides) {
          video.on('ended',function(){
            $(this).off('ended');
            if (slides.size() > 1) {
              sliderData.next();
            }
            else {
              video.trigger('play');
            }
          });
        },
        slideHeight = function () {
          if (splashSliderOwl !== null) {
            var slides = splashSliderOwl.$owlItems || null;
            if (slides !== null) {
              slides.find('[data-ideal-height]').each(function() {
                idealHeight = $(this).data('ideal-height');
                $(this).css('min-height', idealHeight);
              });
            }
          }
        };
        
      slideHeight();
      
      // Event: afterInit
      parrotSplashImageOwlAfterInit = function() {
        var sliderData = this,
          slider = sliderData.$elem,
          slides = sliderData.$owlItems,
          allVideos = slides.find('video') || null;
 
        // Wrapper is hidden with CSS to provide broken loading  
        splashSliderWrapper.addClass('loaded');
        
        // Slider contains video?
        if (allVideos !== null && allVideos.size() > 0) {
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
            if (videoPlay(slides.eq(0).find('video')) === true) {
              videoEnded(slides.eq(0).find('video'), sliderData, slider, slides);
            }
            else {
              sliderData.play();
            }
          }
        }
      };
      
      // Event: BeforeMove
      parrotSplashImageOwlBeforeMove = function() {
        var sliderData = this,
          slider = sliderData.$elem,
          slides = sliderData.$owlItems,
          nextSlide = slides.eq(sliderData.currentItem) || null;
 
        if (nextSlide === null) {
          return;
        }

        if (slider.hasClass('slider-has-videos')) {
          var nextVideo = nextSlide.find('video') || null;
          slides.find('video').trigger('pause');
          sliderData.stop();
          
          if (videoPlay(nextVideo) === true) {
            videoEnded(nextVideo, sliderData, slider, slides);
          }
          else {
            sliderData.play();
          }
        }
      };      
      
      if (splashSliderOwl !== null) {
        splashSliderOwl.options.autoHeight = true;
        splashSliderOwl.options.addClassActive = true;
        splashSliderOwl.options.afterInit = parrotSplashImageOwlAfterInit;
        splashSliderOwl.options.beforeMove = parrotSplashImageOwlBeforeMove;
        splashSliderOwl.reinit(splashSliderOwl.options)
      }
      else {
        // single banner
        // Find any videos & play in loop
        if (splashSliderWrapper.find('video').size() > 0) {
          var video = splashSliderWrapper.find('video'),
            loopCount = 0;
          if (videoPlay(video) === true) {
            video.on('ended',function(){
              ++loopCount;
              video.trigger('play');
              
              // For resource just loop X times
              if (loopCount === singleVideoMaxLoops) {
                $(this).off('ended');
              }
            });
          }
        }
        
        // Set height
        $('[data-ideal-height]').each(function() {
          idealHeight = $(this).data('ideal-height');
          $(this).css('min-height', idealHeight);
        });
        splashSliderWrapper.addClass('loaded');
      }
    }
  };   
  
}(jQuery));
