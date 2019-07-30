# Installation of Dart SDK


1. Download dart SDK
```sh
git clone -b beta https://github.com/flutter/flutter.git
cd flutter/bin/
./flutter
```

2. Location of Dart SDK
```sh
# The dart SDK is located inside
flutter/bin/cache
```

3. Create Dart Project template
   ```sh
    pub global activate stagehead

    # Check template
    stagehand

    #Creation
    mkdir hello_project
    cd hello_Project
    stagehead console-full
    pub get

    ```

4. Dart GitLab CI
   https://gitlab.com/ectucker/dart-ci-example/blob/master/.gitlab-ci.yml
   https://medium.com/@paulchen_9650/%E8%B6%85%E6%96%B0%E6%89%8B%E7%9A%84%E4%B8%80%E6%97%A5ci-cd%E5%88%9D%E9%AB%94%E9%A9%97-%E4%BD%BF%E7%94%A8circleci-github-flow%E8%87%AA%E5%8B%95%E9%83%A8%E7%BD%B2node-js%E6%96%BCaws-elastic-beanstalk-e7af3a65ae61