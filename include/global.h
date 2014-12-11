#ifndef GLOBAL_H
#define GLOBAL_H

typedef unsigned char uchar;

#define MAX_FEAT 200
#define MIN_FEAT 10
#define MAX_QF 100
#define MIN_QF 1
#define MAX_DETT 120
#define MIN_DETT 50
#define MIN_COOP 0
#define MAX_COOP 2

#define N_CAMERA 2

#define TEST_IMAGE_PATH0 "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/test0.jpg"
#define TEST_IMAGE_PATH1 "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/test1.jpg"
#define TEST_IMAGE_PATH2 "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/test2.jpg"

#define CAMERA_CTA 0
#define CAMERA_ATC 1

#define CAMERA_IM_PATH "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/camera.png"
#define CAMERA_IM_PATH_SELECTED "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/camera_selected_new.png"
#define RELAY_IM_PATH "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/relay.png"
#define RELAY_IM_PATH_SELECTED "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/relay_selected_new.png"
#define SINK_IM_PATH "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/sink.png"
#define SINK_IM_PATH_SELECTED "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/sink_selected_new.png"
#define COOP_IM_PATH "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/cooperator.png"
#define COOP_IM_PATH_SELECTED "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_images/cooperator_selected_new.png"

#define XML_NETWORK_PATH "/Users/lucabaroffio/QTworkspace/GreeneyesGUI/Network_config/network_configuration.xml"

#define NETWORK_TOPOLOGY_ROWS 8
#define NETWORK_TOPOLOGY_COLS 8

#define FRAME_W 640
#define FRAME_H 480

#define TCP_PORT 1234

#define HEADER_SIZE 16

enum msg_type {ATC_START = 0, CTA_START = 1, DATC_START = 2, STOP = 3, CTA_INFO = 4, ATC_INFO = 5, DATC_INFO = 6, CTA_DATA = 7, ATC_DATA = 8};
enum cta_op_mode {CTAONESHOT = 0, CTASTREAMING = 1};
enum atc_op_mode {ATCONESHOT = 0, ATCSTREAMING = 1};
enum det_type {BRISKDET = 0, SIFTDET = 1};
enum desc_type {BRISKDESC = 0, SIFTDESC= 1};
enum atc_coding_info {MODEA = 0, MODEB = 1};

#endif // GLOBAL_H

