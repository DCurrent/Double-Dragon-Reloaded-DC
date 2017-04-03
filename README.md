# Double-Dragon-Reloaded-DC

This is an update of the excellent magggas Double Dragon Remake OpenBOR module, given the thumbs up by Magggas himself. :)

The goal of this update is to create an even more faithful representation of the Double Dragon franchise. The extra button devoted to back attacks will be phased out for Double Dragon’s traditional Punch, Kick, Jump controls. In its place is a Defense button as introduced by Return of Double Dragon for the SNES.

To represent the unique Double Dragon 2 style gameplay, and the divergence of Jimmy as the series progressed, Jimmy is being upgraded from palette swap to a fully realized character using the Double Dragon 2 style gameplay from Arcade and NES. Punch and Kick become Left and Right attack respectively. Additionally, Jimmy gains the immensely powerful special attacks from NES DDII.
At the same time, Billy gains some of the advanced command attacks from SNES Return of Double Dragon. The end result is Jimmy being a potent single strike character perfect for advanced players, while Billy is easy to handle and has more ways to break through enemy defenses. The latter advantage stems from enemies also receiving upgrades similar to SNES, where they too have countermeasures against certain attacks.

An emphasis on team moves and importing techniques introduced in later games is also being made, such as the team hurricane kick, vaulting jump kicks, and somersault throw.

Below is the progress made prior to GitHUB:

## General

- Just like World Hereos, a lot of stuff I forget to document before moing to GitHUB... *sigh*.

## Controls

- Back Kick button is removed. New button Defend replaces it.
- Punch and Kick are renamed “Attack A” and “Attack B” as their functions differ depending on which Lee brother is used.

## New Moves

### Complete

- Block.
- Run.
- Somersault.
- Somersault Throw.
- Somersault Kick.
- Backdrop Finisher.
- Double Dragon Hurricane Kick (Double team Hurricane Kick).
- Rear Backhand Strike (w/sticks).
- TKD Kick.
- TKD Finisher. 
- Middle kick (Grab finisher).

### In Progress

- Hyper Uppercut.
- Hyper Knee.
- Dragon’s Tail Kick (Double team jump kick).
- Knee Thrust.

## Modified Moves

- Hurricane kick now requires timing with apex of jump as in the original arcade DDII, but is also more powerful. 
- Stick combo is now a faster four step combo with all unique animations, and hit per button press. Take away Chin’s Kali sticks and show him how it’s done!
- Second strike with chains and whips now has a unique animation.

## Stages

### All

-	Update music to Double Dragon Neon tracks with offsets & loops.

### Stage 1 (City)

- Separate background layers into path, bush, city and sky.
- Upgrade to .png assests.

### Stage 3A (Rooftops)

- Fix bridge grating, it is now a real see through grate.
- Separate background layers.
  - Path
  - Forrest
  - City
  - Mountains
  - Clouds
  - Sky.
- Upgrade to .png assests.

### Stage 3 (Forrest)

- Separate background layers.
  - Path
  - Trees
  - Field
  - Mountains
  - Clouds (multilayer autoscroll)
    - A
    - B
    - C
    - D
  - Sky
- Upgrade to .png assests.

### Stage 4 (Invade Enemy Base)

- Separate background layers.
  - Path
  - Trees A
  - Trees B
  - Sky.
- Upgrade to .png assests.

## Technical

- Refine billkey.c with macros and bitwise operators.
- Jump animations simplified. Previously jump animations included multiple identical frames to control the timing for cancels. These have been replaced by velocity evaluation in keyscripts. The extra frames are removed.

### Resource cleanup 

- Eliminate unused and superfluous assets. Many of Billy’s weapon sprites were identical to the unarmed version. References in the weapon texts switched to unarmed version and the extra sprites removed. Note some small weapon sprites (knifes, dynamite, etc.) were unique, but also unnecessary. Billy carries these items in his far hand while walking. This means they would be hidden by his body when turning to walk upward, but sprites were created showing the weapons remaining visible by inexplicably warping to his near hand. These have been eliminated to serve the double purpose of visual consistency and avoiding wasted resources. 

- Bomb
  - aaaa5
  - aaaa55
  - aaaa6
  - bk0
  - bk4
  - bkick1
  - climb2
  - J00
  - J0
  - Jk2
  - kna4
  - kna5
  - wu1
  - wu2
  - wu3
  - wu4
- Chain
  - bk0
  - bkick1
  - climb2
  - climb3
  - climb4
  - climb5
  - jk2
  - pain1
  - wu1
  - wu1
  - wu3
  - wu4
- Dynamite
  - bk0
  - bk4
  - bkick1
  - kna4
  - kna5
  - pain1
  - Knife
  - bkick1
  - bk4
  - kna4
  - kna5
  - wu1
  - wu2
  - wu3
  - wu4
- knife
  - wu1
  - wu2
  - wu3
  - wu4
- Whip
  - bkick1
  - wu1
  - wu2
  - wu3
  - wu4
- All throwing sprites for heavy objects.






