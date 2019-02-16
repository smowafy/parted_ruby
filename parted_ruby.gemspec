$LOAD_PATH.unshift File.expand_path('../lib', __FILE__)

require 'parted_ruby/version' 

Gem::Specification.new do |s|
  s.name = "parted_ruby"
  s.homepage = "http://github.com/smowafy/parted_ruby"
  s.license = "MIT"
  s.summary = "Ruby binding for libparted"
  s.version = PartedRuby::VERSION
  s.email = "sherif.mowafy@gmail.com"
  s.authors = ["Sherif Mowafy"]
end

