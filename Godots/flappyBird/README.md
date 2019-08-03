# Project setup
1. Create project
2. Editor setting -> file dialog -> list
3. Create audio, font, scripts, sprites, stages, scenes folders
4. Create new `Node`
5. Save as `scenes/game_stage.tscn`
6. Change display to `144*256` `Display -> Window`
7. Create `sprite`, inspector->texture->load
8. Stretch mode `2D`, test-width: `288 512`
9. `?`Image loader: `filter`,`gen_minmaps` off

# Birdie
1. Create Another Scene
    * take care of physics: RigidBody2D
        * Sel the bird and make sure children not selectable (near unlock)
        * show the bird: Animated Sprite
            * Frames > Sprite >Edit > Import Biride
        * take care of collision: CollisionShape2D
        * Take care of the animation: AnimationPlayer

