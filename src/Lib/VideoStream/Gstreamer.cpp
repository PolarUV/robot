#include "Gstreamer.hpp"
#include "VideoDeviceMessage.pb.h"
#include <gst/gst.h>
#include <gst/gstdeviceprovider.h>
#include <iostream>

using namespace lib::processing;

Gstreamer::Gstreamer() :
        src(gst_element_factory_make("v4l2src", "src")),
        h264parse(gst_element_factory_make("h264parse", "parser")),
        rtp(gst_element_factory_make("rtph264pay", "rtp")),
        gdp(gst_element_factory_make("gdppay", "gdp")),
        sink(gst_element_factory_make("udpsink", "sink")),
        group(gst_pipeline_new("rov-pipeline")) {

    gst_bin_add_many(GST_BIN(group), src, h264parse, rtp, gdp, sink, nullptr);
}

void Gstreamer::Start(const Settings &settings) {

    g_object_set(sink, "port", 8000, "host", settings.Ip.cbegin(), nullptr);


    g_object_set(src,
                 "device", settings.DeviceName.cbegin(),
                 "do-timestamp", FALSE,
                 "brightness", settings.Brightness,
                 "contrast", settings.Contrast,
                 "contrast", settings.Hue,
                 "contrast", settings.Saturation,
                 nullptr);

    gst_element_link_many(src, h264parse, rtp, gdp, sink, nullptr);

    gst_element_set_state(group, GST_STATE_PLAYING);
}

void Gstreamer::Stop() {
    gst_element_set_state(group, GST_STATE_NULL);
}

Gstreamer::~Gstreamer() {
    Stop();

    gst_element_link_many(src, h264parse, rtp, gdp, sink, nullptr);
    g_object_unref(group);
}

///ToDo check memory leak
void FindDevices(gpointer data, gpointer user_data) {

    auto device = reinterpret_cast<GstDevice *>(data);

    auto &message = *reinterpret_cast<VideoDeviceMessage *>(user_data);

    auto caps = gst_device_get_caps(device);

    auto structure = gst_caps_get_structure(caps, 0);

    auto name = gst_structure_get_name(structure);

    if (g_str_has_prefix(name, "video/x-h264") != 1)
        return;

    auto prop = gst_device_get_properties(device);

    auto path = gst_structure_get_string(prop, "device.path");

    std::cout << path << std::endl;

    message.add_device_names(path);

}

std::string Gstreamer::ScanCameras() {

    VideoDeviceMessage message;

    auto deviceProvider = gst_device_provider_factory_get_by_name("v4l2deviceprovider");

    auto devices = gst_device_provider_get_devices(deviceProvider);

    g_list_foreach(devices, (GFunc) FindDevices, &message);

    return message.SerializeAsString();
}

extern "C" {
void InitGstreamer() {

    gst_init(nullptr, nullptr);

    GST_PLUGIN_STATIC_DECLARE(coreelements);
    GST_PLUGIN_STATIC_REGISTER(coreelements);

    GST_PLUGIN_STATIC_DECLARE(video4linux2);
    GST_PLUGIN_STATIC_REGISTER(video4linux2);

    GST_PLUGIN_STATIC_DECLARE(videoparsersbad);
    GST_PLUGIN_STATIC_REGISTER(videoparsersbad);

    GST_PLUGIN_STATIC_DECLARE(rtp);
    GST_PLUGIN_STATIC_REGISTER(rtp);

    GST_PLUGIN_STATIC_DECLARE(gdp);
    GST_PLUGIN_STATIC_REGISTER(gdp);

    GST_PLUGIN_STATIC_DECLARE(udp);
    GST_PLUGIN_STATIC_REGISTER(udp);
}
}