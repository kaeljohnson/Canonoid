* ~Render player on screen~
* Render level on screen 
* Optimize game loop.
** Timestep
*** Must be seemless regardless of frame rate and/or processing hiccups.
* Map
* Physics
	-> Need to find good way to hold entity physics state.
		* I.E. What is their position, velocity, and acceleration in reference to window and pixel size.
		* The renderer needs to render the entities each frame depending on how much they have changed in that given frame time.
			-> There may be multiple updates between each frame depending on the display.
	-> Whatever is refered to as the "map" are the tiles in the game that will not move by themselves. They will move when the camera updates, but that will be separate from the physics.
* Camera follow
* Collision detection.
