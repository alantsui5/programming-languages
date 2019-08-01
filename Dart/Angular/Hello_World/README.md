# Hello_World

1. Install `webdev`
```sh
echo 'export PATH="~/Documents/app/flutter/bin/cache/dart-sdk:$PATH"' >> ~/.bashrc
echo 'export PATH="$PATH":"~/Documents/app/flutter/bin"' >> ~/.bashrc
echo 'export PATH="$PATH":"$HOME/.pub-cache/bin"' >> ~/.bashrc
pub global activate webdev
pub global activate stagehand
```

2. Run `Stagehand` templater
```sh
pub global run stagehand <template-name>
```

3. Run `webdev` serve
```sh
pub global run webdev serve --auto=restart
```

A web app that uses [AngularDart](https://webdev.dartlang.org/angular) and
[AngularDart Components](https://webdev.dartlang.org/components).

Created from templates made available by Stagehand under a BSD-style
[license](https://github.com/dart-lang/stagehand/blob/master/LICENSE).
