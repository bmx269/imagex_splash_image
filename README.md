### Splash Image & Slideshow

This feature module provides the default configuration to setup splash image and slideshows using inline entity form fields embedded in nodes. The net effect of the configuration is that it allows you to configure content types to store splash images and slideshows that will be rendered in a banner region of the site on a node-by-node basis. This technique is premised on using panelizer for all content pages. By enabling content administrators to add and configure banners and slideshows on the node they're creating, they avoid having to know a more complicated workflow for getting such site components to render.

## Installation

A drupal-org.make file is included to allow you to build the module dependencies with drush make. This module requires:

- ctools
- ds
- eck
- eck
- entityreference
- features
- filefield_paths
- owlcarousel
- image
- image_url_formatter
- parrot_common_fields
- inline_entity_form
- media
- text
- views
- views_content

*** Note that this module assumes you'll already have installed `ctools`, `ds`, `eck`, `entityreference`, `features`, `filefield_paths`, `owlcarousel`, `image`, `parrot_common_fields`, `media`, `text`, and `views` and as such does not provide them in drupal-org.make. If you don't already have these installed, you'll need to add them manually or include them in your profile's drupal-org.make.


## Roadmap


