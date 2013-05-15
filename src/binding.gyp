{
 'targets': [
    {
      'target_name': 'algorithm',
      'sources': [ 'module.cc' ],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-stdlib=libc++',
          '-mmacosx-version-min=10.7'
        ]
      },
    },
    {
      'target_name': 'math',
      'sources': [ 'sqrt.cc' ],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-stdlib=libc++',
          '-mmacosx-version-min=10.7'
        ]
      },
    },
    {
      'target_name': 'async',
      'sources': [ 'async.cc' ],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-stdlib=libc++',
          '-mmacosx-version-min=10.7',
          '-std=c++11'
        ]
      },
    }
    # Create other targets here...
  ] 
}
