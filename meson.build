project('videofs', ['c', 'cpp'],
    version: '0.0.1',
    license: ' GPL-3.0-or-later',
    default_options: [
        'buildtype=debug',
        'werror=false',
        'warning_level=3'
        ]
)

common_srcs = [
    'src/config.cpp',
    'src/log.cpp',
    'src/util.cpp',
    'src/interconverter_3bpc.cpp',
]

cpp_args = [
    '-pthread',
    '-D_GNU_SOURCE',
    '-DVERSION="' + meson.project_version() + '"'
]

opencv_dep = dependency('opencv4')
fuse_dep = dependency('fuse3')

common_dep = [opencv_dep]

encoder = executable('encoder_test',
    [common_srcs, 'src/encoder_test.cpp'],
    dependencies : [
        common_dep,
        ],
    cpp_args: cpp_args,
    install: true,
    install_dir: get_option('bindir')
)

decoder = executable('decoder_test',
    [common_srcs, 'src/decoder_test.cpp'],
    dependencies : [
        common_dep,
        ],
    cpp_args: cpp_args,
    install: true,
    install_dir: get_option('bindir')
)

run_target('format',
  command : 'scripts/format.sh')
