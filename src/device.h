#ifndef SRC_DEVICE_H_
#define SRC_DEVICE_H

#include "bindings.h"

namespace NodeUsb {
	class Device : public EventEmitter {
		public:
			// called from outside to initalize V8 class template
			static void Initalize(Handle<Object> target);
			static Persistent<FunctionTemplate> constructor_template;
			Device(libusb_device*);
			~Device();

		protected:
			// members
			struct libusb_device *device;
			struct libusb_device_descriptor device_descriptor;
			struct libusb_config_descriptor *config_descriptor;

			// V8 getter
			static Handle<Value> BusNumberGetter(Local<String> property, const AccessorInfo &info);
			static Handle<Value> DeviceAddressGetter(Local<String> property, const AccessorInfo &info);

			// exposed to V8
			static Handle<Value> New(const Arguments& args);
			static Handle<Value> Close(const Arguments& args);
			static Handle<Value> Reset(const Arguments& args);
			static Handle<Value> GetConfigDescriptor(const Arguments& args);
			static Handle<Value> GetDeviceDescriptor(const Arguments& args);
	};
}
#endif
