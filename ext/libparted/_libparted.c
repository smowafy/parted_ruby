/*
 * Parted device module
 */

#include <ruby.h>
#include <parted/parted.h>

VALUE partedrb_device_get_device(VALUE self, VALUE partedrb_path_name) {
  Check_Type(partedrb_path_name, T_STRING);
  PedDevice* device;
  const char* path_name;
  char* internal_device_path_name;
  VALUE partedrb_internal_device_path_name;

  path_name = StringValueCStr(partedrb_path_name);
  device = ped_device_get(path_name);

  internal_device_path_name = device->path;

  partedrb_internal_device_path_name = rb_str_new_cstr(internal_device_path_name);

  rb_iv_set(self, "@path", partedrb_internal_device_path_name);

  return T_NIL;
}

void Init__libparted(void) {
  VALUE modPartedRuby;

  VALUE modPedDevice;
  VALUE modPedUnit;
  VALUE modPedConstraint;
  VALUE modPedDisk;
  VALUE modPedPartition;
  VALUE modPedException;
  VALUE modPedFileSystem;
  VALUE modPedGeometry;
  VALUE modPedAlignment;
  VALUE modPedTimer;

  VALUE klassPedDevice;
  VALUE klassPedDeviceArchOps;
  VALUE klassPedDisk;
  VALUE klassPedDiskArchOps;
  VALUE klassPedException;
  VALUE klassPedFileSystem;
  VALUE klassPedFileSystemType;
  VALUE klassPedGeometry;
  VALUE klassPedPartition;

  modPartedRuby = rb_define_module("PartedRuby");

  modPedUnit = rb_define_module_under(modPartedRuby, "UnitMod");
  modPedConstraint = rb_define_module_under(modPartedRuby, "ConstraintMod");
  modPedDisk = rb_define_module_under(modPartedRuby, "DiskMod");
  modPedPartition = rb_define_module_under(modPedDisk, "PartitionMod");
  modPedException = rb_define_module_under(modPartedRuby, "ExceptionMod");
  modPedFileSystem = rb_define_module_under(modPartedRuby, "FileSystemMod");
  modPedGeometry = rb_define_module_under(modPartedRuby, "GeometryMod");
  modPedAlignment = rb_define_module_under(modPartedRuby, "AlignmentMod");
  modPedTimer = rb_define_module_under(modPartedRuby, "TimerMod");

  klassPedDevice = rb_define_class_under(modPartedRuby, "Device", rb_cObject);
  klassPedDeviceArchOps = rb_define_class_under(modPartedRuby, "DeviceArchOps", rb_cObject);
  klassPedDisk = rb_define_class_under(modPartedRuby, "Disk", rb_cObject);
  klassPedDiskArchOps = rb_define_class_under(modPartedRuby, "DiskArchOps", rb_cObject);
  klassPedException = rb_define_class_under(modPartedRuby, "Exception", rb_cObject);
  klassPedFileSystem = rb_define_class_under(modPartedRuby, "FileSystem", rb_cObject);
  klassPedFileSystemType = rb_define_class_under(modPartedRuby, "FileSystemType", rb_cObject);
  klassPedGeometry = rb_define_class_under(modPartedRuby, "Geometry", rb_cObject);
  klassPedPartition = rb_define_class_under(modPartedRuby, "Partition", rb_cObject);

  rb_define_attr(klassPedDevice, "path", 1, 0);

  rb_define_method(klassPedDevice, "get_device", partedrb_device_get_device, 1);

}
