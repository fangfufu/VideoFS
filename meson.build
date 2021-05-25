project('videofs', 'c',
    version: '0.0.1',
    license: ' GPL-3.0-or-later',
    default_options: [
        'buildtype=debug',
        'werror=true',
        'warning_level=3'
        ]
)

srcs = [
    'src/main.c',
    'src/byteblock_3bpc.c',
    'src/util.c',
    'src/log.c'
]

c_args = [
    '-pthread',
    '-D_GNU_SOURCE',
    '-D_FILE_OFFSET_BITS=64',
    '-DVERSION="' + meson.project_version() + '"'
]

opencv_dep = dependency('opencv4')
fuse_dep = dependency('fuse3')

httpdirfs = executable('httpdirfs',
    srcs,
    dependencies : [opencv_dep, fuse_dep],
    c_args: c_args,
    install: true,
    install_dir: get_option('bindir')
)

run_target('format',
  command : 'scripts/format.sh')
