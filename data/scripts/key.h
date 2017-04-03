// 2016-09-13
// Caskey, Damon
//
// Key flags and key macros. These are mainly for
// use with the key flags property, which can be
// evaluated with bitwise operators to find
// active keys.


#ifndef KEY

#define KEY 1

#define KEY_FLAG_FALSE          0
#define KEY_FLAG_TRUE           1

// System key flags.
#define KEY_ATTACK              openborconstant("FLAG_ATTACK")      // Attack 1.
#define KEY_ATTACK_2            openborconstant("FLAG_ATTACK2")     // Attack 2.
#define KEY_ATTACK_3            openborconstant("FLAG_ATTACK3")     // Attack 3.
#define KEY_ATTACK_4            openborconstant("FLAG_ATTACK4")     // Attack 4.
#define KEY_ESCAPE              openborconstant("FLAG_ESC")         // Escape.
#define KEY_JUMP                openborconstant("FLAG_JUMP")        // Jump.
#define KEY_MOVE_LEFT           openborconstant("FLAG_MOVELEFT")    // Left.
#define KEY_MOVE_RIGHT          openborconstant("FLAG_MOVERIGHT")   // Right.
#define KEY_MOVE_UP             openborconstant("FLAG_MOVEUP")      // Up.
#define KEY_MOVE_DOWN           openborconstant("FLAG_MOVEDOWN")    // Down.
#define KEY_SCREENSHOT          openborconstant("FLAG_SCREENSHOT")  // Screen shot.
#define KEY_SPECIAL             openborconstant("FLAG_SPECIAL")     // Special.

// Custom key combos.
#define KEY_ATTACK_2_AND_JUMP   (player_key_press & KEY_ATTACK_2 && player_key_hold & KEY_JUMP) || (player_key_hold & KEY_ATTACK_2 && player_key_press & KEY_JUMP)
#define KEY_ATTACK_3_AND_JUMP   (player_key_press & KEY_ATTACK_3 && player_key_hold & KEY_JUMP) || (player_key_hold & KEY_ATTACK_3 && player_key_press & KEY_JUMP)
#define KEY_ATTACK_3_ATTACK_2   (player_key_press & KEY_ATTACK_3 && player_key_hold & KEY_ATTACK_2) || (player_key_hold & KEY_ATTACK_3 && player_key_press & KEY_ATTACK_2)

#endif
