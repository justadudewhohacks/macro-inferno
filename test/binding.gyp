{
	"targets": [{
		"target_name": "macro-inferno-test",
		"include_dirs" : [
			"<!(node -e \"require('nan')\")",
			"<!(node -e \"require('macro-inferno')\")",
			"./cc"
		],
		"sources": [
			"cc/index.cc"
		],

		"cflags" : [
			"-std=c++11"
		],
		"cflags!" : [
			"-fno-exceptions"
		],
		"cflags_cc!": [ "-fno-rtti",  "-fno-exceptions"],

		"conditions": [
			[ "OS==\"win\"", {
				"cflags": [
					"-Wall"
				],
				"defines": [
					"WIN",
					"_HAS_EXCEPTIONS=1"
				],
				"msvs_settings": {
					"VCCLCompilerTool": {
						"ExceptionHandling": "2",
						"RuntimeLibrary": "2"
					},
				}
			}]
		]
	}]
}
