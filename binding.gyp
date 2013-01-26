{
  'targets': [
    {
      'target_name': 'binding',
      'sources': [
        'binding.cc'
      ],
      'conditions': [
        ['OS=="mac"', {
          # cflags on OS X are stupid and have to be defined like this
          'defines': [
            '_FILE_OFFSET_BITS=64',
            '_LARGEFILE_SOURCE'
          ],
          'xcode_settings': {
            'OTHER_CFLAGS': [
              '-Wall',
              '-ObjC++'
            ]
          }
        }]
      ]
    }
  ]
}