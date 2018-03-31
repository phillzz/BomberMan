BomberMan Clone

Unreal Engine 4.19.0
---------------------------------------------------------------------
Controls:
	
Player 1

	w - move forward
	s - move backward	
	d - move right
	a - move left
	Space bar - place a bomb. If RemoteControll picked up, press again to activate bomb

Player 2

	Up - move forward
	Down - move backward
	Right - move right
	Left - move left
	NumLock 0 - place a bomb. If RemoteControll picked up, press again to activate bomb
	
---------------------------------------------------------------------	
Classes:

	BombermanCloneGameMode - Spawn game grid and player pawns.
	BombermanCloneCharacter - Contains input logic, pickups implementation and bombs logic. 
	BombermanClonePlayerController - Contain input logic for 2 player.
	GameGrid - Generates play field by spawning detestable and understandable objects
	BombermanGameInstance - contains Win Rate 
	BombermanHUD - display each player info
	Interaction - Interface implemented on most objects
	BP_Camera - Contain camera interpolation view logic for 2 players 
	UndestructableWall - objects that can't be destroyed.
	DestructableWall_Child - objects that can be blown up. In 30% spawn random pickup or bomb.
	BP_Bomb - Blows after 1s as spawned.
	BP_RemoteBomb - Blows on key press (player 1: space bar, player 2 numLock 0) 
	Pickups:
		PickupTemplate - just a template that spawn a particle effect.
		BP_BombLongerBlast = x2 radius of injury;
		BP_FasterRun = x2 speed for 6 seconds;
		BP_MoreBombs = +5 bombs;
		BP_RemoteControll = just remote control.
---------------------------------------------------------------------	
Future Steps:

	- refactoring movement system to grid related 
	- refactoring spawn location for bombs to grid related
	- refactoring bomb blow system (check if the grid location contain object)
	- refactoring remote control system
	- refactoring random algorithm for drops and drop amount 
	- refactoring UI
	- Add to grid playerStart points for spawning players
	- Add some animation to bombs
	- Add camera shake on blow
	- Add sound system
	- Add visual effects

---------------------------------------------------------------------	
All Game related content can be found in BombermanFolder. Note some times you can find redirect to materials from starter content pack. 

Only task that wasn't done: Bonus: AI enemies that behave like a player.


