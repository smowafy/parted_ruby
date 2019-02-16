require 'mkmf'

extension_name = '_libparted'

unless pkg_config('libparted')
  raise "Parted library not installed on the system"
end

create_header
create_makefile(extension_name)
