# encoding: utf-8
# Rakefile: build ruby Libparted bindings

# Credit to this Rakefile pattern goes to
# https://github.com/libvirt/ruby-libvirt


EXT_CONF = 'ext/libparted/extconf.rb'
MAKEFILE = 'ext/libparted/Makefile'
LIBPARTED_SRC = Dir.glob('ext/libparted/*.c')
LIBPARTED_SRC << MAKEFILE 

LIBPARTED_MODULE = 'ext/libparted/_libparted.so'

file MAKEFILE => EXT_CONF do |t|
  Dir::chdir(File::dirname(EXT_CONF)) do
    unless sh "ruby #{File::basename(EXT_CONF)}"
      $stderr.puts 'Failed to run extconf'
    end
  end
end

file LIBPARTED_MODULE => LIBPARTED_SRC do |t|
  Dir::chdir(File::dirname(MAKEFILE)) do
    unless sh "make"
      $stderr.puts 'make failed'
    end
  end
end

task :build => LIBPARTED_MODULE

task :default => :build
