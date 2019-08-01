# Bookmark_Manager

1. Create bookmarks scarfold to replace todo list
    * `bookmark_list/bookmark_list.dart`
2. Inside `bookmark_list_component.dart`
    * ```dart
        import 'package:angular/angular.dart';

        @Component {
            selector:'bm-list',
            template: 'bookmark-list.html',
        }
        class BookmarkListComponent {}
        ```
3. Import the new component to `app_componet.dart`
    * ```dart
        @Component(
            selector: 'my-app',
            styleUrls: ['app_component.css'],
            templateUrl: 'app_component.html',
            directives: [<Component Class Name>],
        )
        ```
4. Import the new component to `app-component.html`
    * ```html
        <component-selector-name></component-selector-name>
        ```
5. Input __Hello World__ inside `bookmark_list_component`
    * ```html
        <h1>Hello World</h1>
        ```

6. Import bootstrap to `index.html`
    * ```html
        <head>
        Bootstrap Links
        </head>
        ```

7. Links reference <br>
https://www.youtube.com/watch?v=7g8Gg2QVdeU&list=PL55RiY5tL51rLqH4-8LBVlUTIFF70dxhb&index=1 <br>
https://medium.com/@GarrettLevine/5-projects-to-complete-when-starting-to-learn-front-end-web-development-48e8a1ce3178


A web app that uses [AngularDart](https://webdev.dartlang.org/angular) and
[AngularDart Components](https://webdev.dartlang.org/components).

Created from templates made available by Stagehand under a BSD-style
[license](https://github.com/dart-lang/stagehand/blob/master/LICENSE).
