require '_libparted'

device_inst = PartedRuby::Device.new

puts device_inst.test_alive

puts device_inst.get_device('/home/smowafy/playarounds/disk-images/scratch.img')

puts device_inst.path


