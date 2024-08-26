project('videofs', ['c', 'cpp'],
    version: '0.0.1',
    license: ' GPL-3.0-or-later',
    default_options: [
        'buildtype=debug',
        'werror=true',
        'warning_level=3'
        ]
)

common_srcs = [
    'src/config.cpp',
    'src/log.cpp',
    'src/util.cpp',
]

cpp_args = [
    '-pthread',
    '-lm',
    '-D_GNU_SOURCE',
    '-DVERSION="' + meson.project_version() + '"'
]

opencv_dep = dependency('opencv4')
fuse_dep = dependency('fuse3')

videofs = executable('encoder',
    [common_srcs, 'src/encoder.cpp'],
    dependencies : [
        opencv_dep,
        fuse_dep
        ],
    cpp_args: cpp_args,
    install: true,
    install_dir: get_option('bindir')
)

run_target('format',
  command : 'scripts/format.sh')
