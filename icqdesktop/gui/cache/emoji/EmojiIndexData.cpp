#if defined(__APPLE__)
    #define EXCLUDE_EMOJI_MAC_10_10 if (QSysInfo().macVersion() > QSysInfo::MV_10_10)
    #define EXCLUDE_EMOJI_MAC_10_9 if (QSysInfo().macVersion() > QSysInfo::MV_10_9)
#else
    #define EXCLUDE_EMOJI_MAC_10_10
    #define EXCLUDE_EMOJI_MAC_10_9
#endif

EmojiIndexByOrder_.reserve(1276);
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 933, 0x1f600, 0x0, "grinning"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 977, 0x1f62c, 0x0, "grimacing"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 934, 0x1f601, 0x0, "grin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 935, 0x1f602, 0x0, "joy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 936, 0x1f603, 0x0, "smiley"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 937, 0x1f604, 0x0, "smile"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 938, 0x1f605, 0x0, "sweat_smile"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 939, 0x1f606, 0x0, "laughing"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 940, 0x1f607, 0x0, "innocent"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 942, 0x1f609, 0x0, "wink"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 943, 0x1f60a, 0x0, "blush"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 999, 0x1f642, 0x0, "slight_smile"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1000, 0x1f643, 0x0, "upside_down"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1173, 0x263a, 0x0, "relaxed"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 944, 0x1f60b, 0x0, "yum"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 945, 0x1f60c, 0x0, "relieved"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 946, 0x1f60d, 0x0, "heart_eyes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 957, 0x1f618, 0x0, "kissing_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 956, 0x1f617, 0x0, "kissing"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 958, 0x1f619, 0x0, "kissing_smiling_eyes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 959, 0x1f61a, 0x0, "kissing_closed_eyes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 961, 0x1f61c, 0x0, "stuck_out_tongue_winking_eye"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 962, 0x1f61d, 0x0, "stuck_out_tongue_closed_eyes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 960, 0x1f61b, 0x0, "stuck_out_tongue"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1101, 0x1f911, 0x0, "money_mouth"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1103, 0x1f913, 0x0, "nerd"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 947, 0x1f60e, 0x0, "sunglasses"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1107, 0x1f917, 0x0, "hugging"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 948, 0x1f60f, 0x0, "smirk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 987, 0x1f636, 0x0, "no_mouth"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 949, 0x1f610, 0x0, "neutral_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 950, 0x1f611, 0x0, "expressionless"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 951, 0x1f612, 0x0, "unamused"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1001, 0x1f644, 0x0, "rolling_eyes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1104, 0x1f914, 0x0, "thinking"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 984, 0x1f633, 0x0, "flushed"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 963, 0x1f61e, 0x0, "disappointed"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 964, 0x1f61f, 0x0, "worried"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 965, 0x1f620, 0x0, "angry"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 966, 0x1f621, 0x0, "rage"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 953, 0x1f614, 0x0, "pensive"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 954, 0x1f615, 0x0, "confused"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 998, 0x1f641, 0x0, "slight_frown"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1172, 0x2639, 0x0, "frowning2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 968, 0x1f623, 0x0, "persevere"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 955, 0x1f616, 0x0, "confounded"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 976, 0x1f62b, 0x0, "tired_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 974, 0x1f629, 0x0, "weary"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 969, 0x1f624, 0x0, "triumph"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 979, 0x1f62e, 0x0, "open_mouth"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 982, 0x1f631, 0x0, "scream"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 973, 0x1f628, 0x0, "fearful"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 981, 0x1f630, 0x0, "cold_sweat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 980, 0x1f62f, 0x0, "hushed"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 971, 0x1f626, 0x0, "frowning"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 972, 0x1f627, 0x0, "anguished"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 967, 0x1f622, 0x0, "cry"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 970, 0x1f625, 0x0, "disappointed_relieved"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 975, 0x1f62a, 0x0, "sleepy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 952, 0x1f613, 0x0, "sweat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 978, 0x1f62d, 0x0, "sob"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 986, 0x1f635, 0x0, "dizzy_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 983, 0x1f632, 0x0, "astonished"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1100, 0x1f910, 0x0, "zipper_mouth"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 988, 0x1f637, 0x0, "mask"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1102, 0x1f912, 0x0, "thermometer_face"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1105, 0x1f915, 0x0, "head_bandage"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 985, 0x1f634, 0x0, "sleeping"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 709, 0x1f4a4, 0x0, "zzz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 714, 0x1f4a9, 0x0, "poop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 941, 0x1f608, 0x0, "smiling_imp"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 672, 0x1f47f, 0x0, "imp"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 666, 0x1f479, 0x0, "japanese_ogre"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 667, 0x1f47a, 0x0, "japanese_goblin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 673, 0x1f480, 0x0, "skull"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 668, 0x1f47b, 0x0, "ghost"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 670, 0x1f47d, 0x0, "alien"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1106, 0x1f916, 0x0, "robot"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 991, 0x1f63a, 0x0, "smiley_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 989, 0x1f638, 0x0, "smile_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 990, 0x1f639, 0x0, "joy_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 992, 0x1f63b, 0x0, "heart_eyes_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 993, 0x1f63c, 0x0, "smirk_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 994, 0x1f63d, 0x0, "kissing_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 997, 0x1f640, 0x0, "scream_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 996, 0x1f63f, 0x0, "crying_cat_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 995, 0x1f63e, 0x0, "pouting_cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1009, 0x1f64c, 0x0, "raised_hands"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 624, 0x1f44f, 0x0, "clap"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 620, 0x1f44b, 0x0, "wave"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 622, 0x1f44d, 0x0, "thumbsup"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 623, 0x1f44e, 0x0, "thumbsdown"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 619, 0x1f44a, 0x0, "punch"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1234, 0x270a, 0x0, "fist"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1236, 0x270c, 0x0, "v"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 621, 0x1f44c, 0x0, "ok_hand"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1235, 0x270b, 0x0, "raised_hand"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 625, 0x1f450, 0x0, "open_hands"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 715, 0x1f4aa, 0x0, "muscle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1012, 0x1f64f, 0x0, "pray"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1163, 0x261d, 0x0, "point_up"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 615, 0x1f446, 0x0, "point_up_2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 616, 0x1f447, 0x0, "point_down"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 617, 0x1f448, 0x0, "point_left"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 618, 0x1f449, 0x0, "point_right"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 907, 0x1f595, 0x0, "middle_finger"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 906, 0x1f590, 0x0, "hand_splayed"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1108, 0x1f918, 0x0, "metal"));
}
EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 908, 0x1f596, 0x0, "vulcan"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1237, 0x270d, 0x0, "writing_hand"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 678, 0x1f485, 0x0, "nail_care"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 613, 0x1f444, 0x0, "lips"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 614, 0x1f445, 0x0, "tongue"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 611, 0x1f442, 0x0, "ear"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 612, 0x1f443, 0x0, "nose"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 609, 0x1f441, 0x0, "eye"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 608, 0x1f440, 0x0, "eyes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 645, 0x1f464, 0x0, "bust_in_silhouette"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 646, 0x1f465, 0x0, "busts_in_silhouette"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 924, 0x1f5e3, 0x0, "speaking_head"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 663, 0x1f476, 0x0, "baby"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 647, 0x1f466, 0x0, "boy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 648, 0x1f467, 0x0, "girl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 649, 0x1f468, 0x0, "man"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 650, 0x1f469, 0x0, "woman"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 658, 0x1f471, 0x0, "person_with_blond_hair"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 661, 0x1f474, 0x0, "older_man"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 662, 0x1f475, 0x0, "older_woman"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 659, 0x1f472, 0x0, "man_with_gua_pi_mao"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 660, 0x1f473, 0x0, "man_with_turban"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 655, 0x1f46e, 0x0, "cop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 664, 0x1f477, 0x0, "construction_worker"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 675, 0x1f482, 0x0, "guardsman"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 896, 0x1f575, 0x0, "spy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 434, 0x1f385, 0x0, "santa"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 669, 0x1f47c, 0x0, "angel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 665, 0x1f478, 0x0, "princess"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 657, 0x1f470, 0x0, "bride_with_veil"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1067, 0x1f6b6, 0x0, "walking"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 491, 0x1f3c3, 0x0, "runner"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 676, 0x1f483, 0x0, "dancer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 656, 0x1f46f, 0x0, "dancers"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 652, 0x1f46b, 0x0, "couple"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 653, 0x1f46c, 0x0, "two_men_holding_hands"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 654, 0x1f46d, 0x0, "two_women_holding_hands"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1004, 0x1f647, 0x0, "bow"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 674, 0x1f481, 0x0, "information_desk_person"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1002, 0x1f645, 0x0, "no_good"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1003, 0x1f646, 0x0, "ok_woman"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1008, 0x1f64b, 0x0, "raising_hand"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1011, 0x1f64e, 0x0, "person_with_pouting_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1010, 0x1f64d, 0x0, "person_frowning"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 680, 0x1f487, 0x0, "haircut"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 679, 0x1f486, 0x0, "massage"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 690, 0x1f491, 0x0, "couple_with_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 688, 0x1f48f, 0x0, "couplekiss"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 651, 0x1f46a, 0x0, "family"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 635, 0x1f45a, 0x0, "womans_clothes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 630, 0x1f455, 0x0, "shirt"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 631, 0x1f456, 0x0, "jeans"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 629, 0x1f454, 0x0, "necktie"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 632, 0x1f457, 0x0, "dress"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 634, 0x1f459, 0x0, "bikini"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 633, 0x1f458, 0x0, "kimono"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 677, 0x1f484, 0x0, "lipstick"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 684, 0x1f48b, 0x0, "kiss"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 644, 0x1f463, 0x0, "footprints"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 641, 0x1f460, 0x0, "high_heel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 642, 0x1f461, 0x0, "sandal"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 643, 0x1f462, 0x0, "boot"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 639, 0x1f45e, 0x0, "mans_shoe"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 640, 0x1f45f, 0x0, "athletic_shoe"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 627, 0x1f452, 0x0, "womans_hat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 465, 0x1f3a9, 0x0, "tophat"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 1214, 0x26d1, 0x0, "helmet_with_cross"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 448, 0x1f393, 0x0, "mortar_board"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 626, 0x1f451, 0x0, "crown"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 447, 0x1f392, 0x0, "school_satchel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 638, 0x1f45d, 0x0, "pouch"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 636, 0x1f45b, 0x0, "purse"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 637, 0x1f45c, 0x0, "handbag"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 733, 0x1f4bc, 0x0, "briefcase"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 628, 0x1f453, 0x0, "eyeglasses"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 897, 0x1f576, 0x0, "dark_sunglasses"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 686, 0x1f48d, 0x0, "ring"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("people", 305, 0x1f302, 0x0, "closed_umbrella"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 598, 0x1f436, 0x0, "dog"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 593, 0x1f431, 0x0, "cat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 589, 0x1f42d, 0x0, "mouse"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 601, 0x1f439, 0x0, "hamster"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 592, 0x1f430, 0x0, "rabbit"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 603, 0x1f43b, 0x0, "bear"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 604, 0x1f43c, 0x0, "panda_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 584, 0x1f428, 0x0, "koala"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 591, 0x1f42f, 0x0, "tiger"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1110, 0x1f981, 0x0, "lion_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 590, 0x1f42e, 0x0, "cow"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 599, 0x1f437, 0x0, "pig"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 605, 0x1f43d, 0x0, "pig_nose"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 600, 0x1f438, 0x0, "frog"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 569, 0x1f419, 0x0, "octopus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 597, 0x1f435, 0x0, "monkey_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1005, 0x1f648, 0x0, "see_no_evil"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1006, 0x1f649, 0x0, "hear_no_evil"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1007, 0x1f64a, 0x0, "speak_no_evil"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 562, 0x1f412, 0x0, "monkey"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 564, 0x1f414, 0x0, "chicken"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 583, 0x1f427, 0x0, "penguin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 582, 0x1f426, 0x0, "bird"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 580, 0x1f424, 0x0, "baby_chick"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 579, 0x1f423, 0x0, "hatching_chick"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 581, 0x1f425, 0x0, "hatched_chick"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 602, 0x1f43a, 0x0, "wolf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 567, 0x1f417, 0x0, "boar"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 596, 0x1f434, 0x0, "horse"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1113, 0x1f984, 0x0, "unicorn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 573, 0x1f41d, 0x0, "bee"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 571, 0x1f41b, 0x0, "bug"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 556, 0x1f40c, 0x0, "snail"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 574, 0x1f41e, 0x0, "beetle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 572, 0x1f41c, 0x0, "ant"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 898, 0x1f577, 0x0, "spider"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1111, 0x1f982, 0x0, "scorpion"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1109, 0x1f980, 0x0, "crab"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 557, 0x1f40d, 0x0, "snake"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 578, 0x1f422, 0x0, "turtle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 576, 0x1f420, 0x0, "tropical_fish"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 575, 0x1f41f, 0x0, "fish"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 577, 0x1f421, 0x0, "blowfish"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 588, 0x1f42c, 0x0, "dolphin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 595, 0x1f433, 0x0, "whale"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 555, 0x1f40b, 0x0, "whale2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 554, 0x1f40a, 0x0, "crocodile"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 550, 0x1f406, 0x0, "leopard"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 549, 0x1f405, 0x0, "tiger2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 547, 0x1f403, 0x0, "water_buffalo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 546, 0x1f402, 0x0, "ox"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 548, 0x1f404, 0x0, "cow2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 586, 0x1f42a, 0x0, "dromedary_camel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 587, 0x1f42b, 0x0, "camel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 568, 0x1f418, 0x0, "elephant"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 560, 0x1f410, 0x0, "goat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 559, 0x1f40f, 0x0, "ram"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 561, 0x1f411, 0x0, "sheep"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 558, 0x1f40e, 0x0, "racehorse"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 566, 0x1f416, 0x0, "pig2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 544, 0x1f400, 0x0, "rat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 545, 0x1f401, 0x0, "mouse2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 563, 0x1f413, 0x0, "rooster"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1112, 0x1f983, 0x0, "turkey"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 863, 0x1f54a, 0x0, "dove"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 565, 0x1f415, 0x0, "dog2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 585, 0x1f429, 0x0, "poodle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 552, 0x1f408, 0x0, "cat2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 551, 0x1f407, 0x0, "rabbit2"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 607, 0x1f43f, 0x0, "chipmunk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 606, 0x1f43e, 0x0, "feet"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 553, 0x1f409, 0x0, "dragon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 594, 0x1f432, 0x0, "dragon_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 354, 0x1f335, 0x0, "cactus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 433, 0x1f384, 0x0, "christmas_tree"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 351, 0x1f332, 0x0, "evergreen_tree"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 352, 0x1f333, 0x0, "deciduous_tree"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 353, 0x1f334, 0x0, "palm_tree"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 350, 0x1f331, 0x0, "seedling"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 364, 0x1f33f, 0x0, "herb"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1162, 0x2618, 0x0, "shamrock"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 365, 0x1f340, 0x0, "four_leaf_clover"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 442, 0x1f38d, 0x0, "bamboo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 440, 0x1f38b, 0x0, "tanabata_tree"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 368, 0x1f343, 0x0, "leaves"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 367, 0x1f342, 0x0, "fallen_leaf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 366, 0x1f341, 0x0, "maple_leaf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 363, 0x1f33e, 0x0, "ear_of_rice"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 359, 0x1f33a, 0x0, "hibiscus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 360, 0x1f33b, 0x0, "sunflower"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 358, 0x1f339, 0x0, "rose"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 356, 0x1f337, 0x0, "tulip"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 361, 0x1f33c, 0x0, "blossom"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 357, 0x1f338, 0x0, "cherry_blossom"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 689, 0x1f490, 0x0, "bouquet"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 369, 0x1f344, 0x0, "mushroom"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 349, 0x1f330, 0x0, "chestnut"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 432, 0x1f383, 0x0, "jack_o_lantern"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 570, 0x1f41a, 0x0, "shell"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 899, 0x1f578, 0x0, "spider_web"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 317, 0x1f30e, 0x0, "earth_americas"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 316, 0x1f30d, 0x0, "earth_africa"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 318, 0x1f30f, 0x0, "earth_asia"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 324, 0x1f315, 0x0, "full_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 325, 0x1f316, 0x0, "waning_gibbous_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 326, 0x1f317, 0x0, "last_quarter_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 327, 0x1f318, 0x0, "waning_crescent_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 320, 0x1f311, 0x0, "new_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 321, 0x1f312, 0x0, "waxing_crescent_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 322, 0x1f313, 0x0, "first_quarter_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 323, 0x1f314, 0x0, "waxing_gibbous_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 329, 0x1f31a, 0x0, "new_moon_with_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 332, 0x1f31d, 0x0, "full_moon_with_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 330, 0x1f31b, 0x0, "first_quarter_moon_with_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 331, 0x1f31c, 0x0, "last_quarter_moon_with_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 333, 0x1f31e, 0x0, "sun_with_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 328, 0x1f319, 0x0, "crescent_moon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1270, 0x2b50, 0x0, "star"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 334, 0x1f31f, 0x0, "star2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 716, 0x1f4ab, 0x0, "dizzy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1244, 0x2728, 0x0, "sparkles"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1157, 0x2604, 0x0, "comet"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1153, 0x2600, 0x0, "sunny"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 337, 0x1f324, 0x0, "white_sun_small_cloud"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1210, 0x26c5, 0x0, "partly_sunny"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 338, 0x1f325, 0x0, "white_sun_cloud"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 339, 0x1f326, 0x0, "white_sun_rain_cloud"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1154, 0x2601, 0x0, "cloud"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 340, 0x1f327, 0x0, "cloud_rain"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1211, 0x26c8, 0x0, "thunder_cloud_rain"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 342, 0x1f329, 0x0, "cloud_lightning"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1202, 0x26a1, 0x0, "zap"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 837, 0x1f525, 0x0, "fire"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 710, 0x1f4a5, 0x0, "boom"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1247, 0x2744, 0x0, "snowflake"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 341, 0x1f328, 0x0, "cloud_snow"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1156, 0x2603, 0x0, "snowman2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1209, 0x26c4, 0x0, "snowman"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 345, 0x1f32c, 0x0, "wind_blowing_face"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 713, 0x1f4a8, 0x0, "dash"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 343, 0x1f32a, 0x0, "cloud_tornado"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 344, 0x1f32b, 0x0, "fog"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1155, 0x2602, 0x0, "umbrella2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 1160, 0x2614, 0x0, "umbrella"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 712, 0x1f4a7, 0x0, "droplet"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 711, 0x1f4a6, 0x0, "sweat_drops"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("nature", 313, 0x1f30a, 0x0, "ocean"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 380, 0x1f34f, 0x0, "green_apple"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 379, 0x1f34e, 0x0, "apple"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 381, 0x1f350, 0x0, "pear"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 375, 0x1f34a, 0x0, "tangerine"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 376, 0x1f34b, 0x0, "lemon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 377, 0x1f34c, 0x0, "banana"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 374, 0x1f349, 0x0, "watermelon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 372, 0x1f347, 0x0, "grapes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 384, 0x1f353, 0x0, "strawberry"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 373, 0x1f348, 0x0, "melon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 383, 0x1f352, 0x0, "cherries"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 382, 0x1f351, 0x0, "peach"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 378, 0x1f34d, 0x0, "pineapple"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 370, 0x1f345, 0x0, "tomato"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 371, 0x1f346, 0x0, "eggplant"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 355, 0x1f336, 0x0, "hot_pepper"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 362, 0x1f33d, 0x0, "corn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 397, 0x1f360, 0x0, "sweet_potato"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 412, 0x1f36f, 0x0, "honey_pot"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 395, 0x1f35e, 0x0, "bread"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 1114, 0x1f9c0, 0x0, "cheese"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 388, 0x1f357, 0x0, "poultry_leg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 387, 0x1f356, 0x0, "meat_on_bone"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 401, 0x1f364, 0x0, "fried_shrimp"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 416, 0x1f373, 0x0, "egg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 385, 0x1f354, 0x0, "hamburger"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 396, 0x1f35f, 0x0, "fries"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 346, 0x1f32d, 0x0, "hotdog"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 386, 0x1f355, 0x0, "pizza"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 394, 0x1f35d, 0x0, "spaghetti"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 347, 0x1f32e, 0x0, "taco"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 348, 0x1f32f, 0x0, "burrito"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 393, 0x1f35c, 0x0, "ramen"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 415, 0x1f372, 0x0, "stew"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 402, 0x1f365, 0x0, "fish_cake"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 400, 0x1f363, 0x0, "sushi"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 414, 0x1f371, 0x0, "bento"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 392, 0x1f35b, 0x0, "curry"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 390, 0x1f359, 0x0, "rice_ball"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 391, 0x1f35a, 0x0, "rice"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 389, 0x1f358, 0x0, "rice_cracker"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 399, 0x1f362, 0x0, "oden"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 398, 0x1f361, 0x0, "dango"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 404, 0x1f367, 0x0, "shaved_ice"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 405, 0x1f368, 0x0, "ice_cream"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 403, 0x1f366, 0x0, "icecream"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 413, 0x1f370, 0x0, "cake"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 431, 0x1f382, 0x0, "birthday"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 411, 0x1f36e, 0x0, "custard"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 409, 0x1f36c, 0x0, "candy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 410, 0x1f36d, 0x0, "lollipop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 408, 0x1f36b, 0x0, "chocolate_bar"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 428, 0x1f37f, 0x0, "popcorn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 406, 0x1f369, 0x0, "doughnut"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 407, 0x1f36a, 0x0, "cookie"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 423, 0x1f37a, 0x0, "beer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 424, 0x1f37b, 0x0, "beers"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 420, 0x1f377, 0x0, "wine_glass"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 421, 0x1f378, 0x0, "cocktail"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 422, 0x1f379, 0x0, "tropical_drink"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 427, 0x1f37e, 0x0, "champagne"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 419, 0x1f376, 0x0, "sake"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 418, 0x1f375, 0x0, "tea"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 1161, 0x2615, 0x0, "coffee"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 425, 0x1f37c, 0x0, "baby_bottle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 417, 0x1f374, 0x0, "fork_and_knife"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("foods", 426, 0x1f37d, 0x0, "fork_knife_plate"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1207, 0x26bd, 0x0, "soccer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 488, 0x1f3c0, 0x0, "basketball"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 496, 0x1f3c8, 0x0, "football"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1208, 0x26be, 0x0, "baseball"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 486, 0x1f3be, 0x0, "tennis"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 504, 0x1f3d0, 0x0, "volleyball"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 497, 0x1f3c9, 0x0, "rugby_football"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 473, 0x1f3b1, 0x0, "8ball"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1222, 0x26f3, 0x0, "golf"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 500, 0x1f3cc, 0x0, "golfer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 507, 0x1f3d3, 0x0, "ping_pong"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 541, 0x1f3f8, 0x0, "badminton"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 506, 0x1f3d2, 0x0, "hockey"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 505, 0x1f3d1, 0x0, "field_hockey"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 503, 0x1f3cf, 0x0, "cricket"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 487, 0x1f3bf, 0x0, "ski"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1225, 0x26f7, 0x0, "skier"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 490, 0x1f3c2, 0x0, "snowboarder"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1226, 0x26f8, 0x0, "ice_skate"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 542, 0x1f3f9, 0x0, "bow_and_arrow"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 459, 0x1f3a3, 0x0, "fishing_pole_and_fish"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1048, 0x1f6a3, 0x0, "rowboat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 498, 0x1f3ca, 0x0, "swimmer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 492, 0x1f3c4, 0x0, "surfer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1077, 0x1f6c0, 0x0, "bath"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1227, 0x26f9, 0x0, "basketball_player"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 499, 0x1f3cb, 0x0, "lifter"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1065, 0x1f6b4, 0x0, "bicyclist"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 1066, 0x1f6b5, 0x0, "mountain_bicyclist"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 495, 0x1f3c7, 0x0, "horse_racing"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 895, 0x1f574, 0x0, "levitate"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 494, 0x1f3c6, 0x0, "trophy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 485, 0x1f3bd, 0x0, "running_shirt_with_sash"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 493, 0x1f3c5, 0x0, "medal"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 449, 0x1f396, 0x0, "military_medal"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 450, 0x1f397, 0x0, "reminder_ribbon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 539, 0x1f3f5, 0x0, "rosette"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 467, 0x1f3ab, 0x0, "ticket"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 455, 0x1f39f, 0x0, "tickets"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 469, 0x1f3ad, 0x0, "performing_arts"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 464, 0x1f3a8, 0x0, "art"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 466, 0x1f3aa, 0x0, "circus_tent"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 460, 0x1f3a4, 0x0, "microphone"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 463, 0x1f3a7, 0x0, "headphones"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 484, 0x1f3bc, 0x0, "musical_score"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 481, 0x1f3b9, 0x0, "musical_keyboard"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 479, 0x1f3b7, 0x0, "saxophone"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 482, 0x1f3ba, 0x0, "trumpet"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 480, 0x1f3b8, 0x0, "guitar"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 483, 0x1f3bb, 0x0, "violin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 468, 0x1f3ac, 0x0, "clapper"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 470, 0x1f3ae, 0x0, "video_game"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 671, 0x1f47e, 0x0, "space_invader"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 471, 0x1f3af, 0x0, "dart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 474, 0x1f3b2, 0x0, "game_die"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 472, 0x1f3b0, 0x0, "slot_machine"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("activity", 475, 0x1f3b3, 0x0, "bowling"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1036, 0x1f697, 0x0, "red_car"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1034, 0x1f695, 0x0, "taxi"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1038, 0x1f699, 0x0, "blue_car"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1025, 0x1f68c, 0x0, "bus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1027, 0x1f68e, 0x0, "trolleybus"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 502, 0x1f3ce, 0x0, "race_car"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1032, 0x1f693, 0x0, "police_car"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1030, 0x1f691, 0x0, "ambulance"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1031, 0x1f692, 0x0, "fire_engine"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1029, 0x1f690, 0x0, "minibus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1039, 0x1f69a, 0x0, "truck"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1040, 0x1f69b, 0x0, "articulated_lorry"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1041, 0x1f69c, 0x0, "tractor"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 501, 0x1f3cd, 0x0, "motorcycle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1063, 0x1f6b2, 0x0, "bike"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1053, 0x1f6a8, 0x0, "rotating_light"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1033, 0x1f694, 0x0, "oncoming_police_car"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1026, 0x1f68d, 0x0, "oncoming_bus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1037, 0x1f698, 0x0, "oncoming_automobile"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1035, 0x1f696, 0x0, "oncoming_taxi"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1046, 0x1f6a1, 0x0, "aerial_tramway"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1045, 0x1f6a0, 0x0, "mountain_cableway"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1044, 0x1f69f, 0x0, "suspension_railway"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1016, 0x1f683, 0x0, "railway_car"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1024, 0x1f68b, 0x0, "train"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1042, 0x1f69d, 0x0, "monorail"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1017, 0x1f684, 0x0, "bullettrain_side"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1018, 0x1f685, 0x0, "bullettrain_front"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1021, 0x1f688, 0x0, "light_rail"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1043, 0x1f69e, 0x0, "mountain_railway"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1015, 0x1f682, 0x0, "steam_locomotive"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1019, 0x1f686, 0x0, "train2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1020, 0x1f687, 0x0, "metro"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1023, 0x1f68a, 0x0, "tram"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1022, 0x1f689, 0x0, "station"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1014, 0x1f681, 0x0, "helicopter"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1095, 0x1f6e9, 0x0, "airplane_small"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1232, 0x2708, 0x0, "airplane"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1096, 0x1f6eb, 0x0, "airplane_departure"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1097, 0x1f6ec, 0x0, "airplane_arriving"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1224, 0x26f5, 0x0, "sailboat"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1094, 0x1f6e5, 0x0, "motorboat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1049, 0x1f6a4, 0x0, "speedboat"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1223, 0x26f4, 0x0, "ferry"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1099, 0x1f6f3, 0x0, "cruise_ship"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1013, 0x1f680, 0x0, "rocket"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1098, 0x1f6f0, 0x0, "satellite_orbital"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 731, 0x1f4ba, 0x0, "seat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1194, 0x2693, 0x0, "anchor"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1052, 0x1f6a7, 0x0, "construction"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1229, 0x26fd, 0x0, "fuelpump"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1028, 0x1f68f, 0x0, "busstop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1051, 0x1f6a6, 0x0, "vertical_traffic_light"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1050, 0x1f6a5, 0x0, "traffic_light"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 489, 0x1f3c1, 0x0, "checkered_flag"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1047, 0x1f6a2, 0x0, "ship"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 457, 0x1f3a1, 0x0, "ferris_wheel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 458, 0x1f3a2, 0x0, "roller_coaster"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 456, 0x1f3a0, 0x0, "carousel_horse"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 511, 0x1f3d7, 0x0, "construction_site"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 304, 0x1f301, 0x0, "foggy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 929, 0x1f5fc, 0x0, "tokyo_tower"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 533, 0x1f3ed, 0x0, "factory"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1221, 0x26f2, 0x0, "fountain"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 446, 0x1f391, 0x0, "rice_scene"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1219, 0x26f0, 0x0, "mountain"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 508, 0x1f3d4, 0x0, "mountain_snow"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 928, 0x1f5fb, 0x0, "mount_fuji"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 314, 0x1f30b, 0x0, "volcano"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 931, 0x1f5fe, 0x0, "japan"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 509, 0x1f3d5, 0x0, "camping"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1228, 0x26fa, 0x0, "tent"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 518, 0x1f3de, 0x0, "park"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1092, 0x1f6e3, 0x0, "motorway"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1093, 0x1f6e4, 0x0, "railway_track"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 308, 0x1f305, 0x0, "sunrise"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 307, 0x1f304, 0x0, "sunrise_over_mountains"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 516, 0x1f3dc, 0x0, "desert"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 510, 0x1f3d6, 0x0, "beach"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 517, 0x1f3dd, 0x0, "island"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 310, 0x1f307, 0x0, "city_sunset"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 309, 0x1f306, 0x0, "city_dusk"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 513, 0x1f3d9, 0x0, "cityscape"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 306, 0x1f303, 0x0, "night_with_stars"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 312, 0x1f309, 0x0, "bridge_at_night"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 315, 0x1f30c, 0x0, "milky_way"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 335, 0x1f320, 0x0, "stars"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 436, 0x1f387, 0x0, "sparkler"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 435, 0x1f386, 0x0, "fireworks"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 311, 0x1f308, 0x0, "rainbow"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 512, 0x1f3d8, 0x0, "homes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 536, 0x1f3f0, 0x0, "european_castle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 535, 0x1f3ef, 0x0, "japanese_castle"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 519, 0x1f3df, 0x0, "stadium"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 930, 0x1f5fd, 0x0, "statue_of_liberty"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 520, 0x1f3e0, 0x0, "house"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 521, 0x1f3e1, 0x0, "house_with_garden"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 514, 0x1f3da, 0x0, "house_abandoned"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 522, 0x1f3e2, 0x0, "office"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 532, 0x1f3ec, 0x0, "department_store"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 523, 0x1f3e3, 0x0, "post_office"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 524, 0x1f3e4, 0x0, "european_post_office"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 525, 0x1f3e5, 0x0, "hospital"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 526, 0x1f3e6, 0x0, "bank"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 528, 0x1f3e8, 0x0, "hotel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 530, 0x1f3ea, 0x0, "convenience_store"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 531, 0x1f3eb, 0x0, "school"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 529, 0x1f3e9, 0x0, "love_hotel"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 691, 0x1f492, 0x0, "wedding"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 515, 0x1f3db, 0x0, "classical_building"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1218, 0x26ea, 0x0, "church"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 865, 0x1f54c, 0x0, "mosque"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 866, 0x1f54d, 0x0, "synagogue"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 864, 0x1f54b, 0x0, "kaaba"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("travel", 1217, 0x26e9, 0x0, "shinto_shrine"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1127, 0x231a, 0x0, "watch"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 786, 0x1f4f1, 0x0, "iphone"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 787, 0x1f4f2, 0x0, "calling"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 732, 0x1f4bb, 0x0, "computer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1129, 0x2328, 0x0, "keyboard"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 909, 0x1f5a5, 0x0, "desktop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 910, 0x1f5a8, 0x0, "printer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 911, 0x1f5b1, 0x0, "mouse_three_button"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 912, 0x1f5b2, 0x0, "trackball"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 900, 0x1f579, 0x0, "joystick"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 920, 0x1f5dc, 0x0, "compression"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 734, 0x1f4bd, 0x0, "minidisc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 735, 0x1f4be, 0x0, "floppy_disk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 736, 0x1f4bf, 0x0, "cd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 737, 0x1f4c0, 0x0, "dvd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 797, 0x1f4fc, 0x0, "vhs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 792, 0x1f4f7, 0x0, "camera"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 793, 0x1f4f8, 0x0, "camera_with_flash"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 794, 0x1f4f9, 0x0, "video_camera"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 461, 0x1f3a5, 0x0, "movie_camera"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 798, 0x1f4fd, 0x0, "projector"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 454, 0x1f39e, 0x0, "film_frames"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 767, 0x1f4de, 0x0, "telephone_receiver"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1158, 0x260e, 0x0, "telephone"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 768, 0x1f4df, 0x0, "pager"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 769, 0x1f4e0, 0x0, "fax"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 795, 0x1f4fa, 0x0, "tv"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 796, 0x1f4fb, 0x0, "radio"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 451, 0x1f399, 0x0, "microphone2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 452, 0x1f39a, 0x0, "level_slider"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 453, 0x1f39b, 0x0, "control_knobs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1138, 0x23f1, 0x0, "stopwatch"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1139, 0x23f2, 0x0, "timer"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1137, 0x23f0, 0x0, "alarm_clock"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 893, 0x1f570, 0x0, "clock"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1140, 0x23f3, 0x0, "hourglass_flowing_sand"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1128, 0x231b, 0x0, "hourglass"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 770, 0x1f4e1, 0x0, "satellite"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 811, 0x1f50b, 0x0, "battery"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 812, 0x1f50c, 0x0, "electric_plug"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 706, 0x1f4a1, 0x0, "bulb"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 838, 0x1f526, 0x0, "flashlight"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 892, 0x1f56f, 0x0, "candle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 917, 0x1f5d1, 0x0, "wastebasket"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1091, 0x1f6e2, 0x0, "oil"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 729, 0x1f4b8, 0x0, "money_with_wings"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 726, 0x1f4b5, 0x0, "dollar"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 725, 0x1f4b4, 0x0, "yen"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 727, 0x1f4b6, 0x0, "euro"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 728, 0x1f4b7, 0x0, "pound"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 721, 0x1f4b0, 0x0, "moneybag"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 724, 0x1f4b3, 0x0, "credit_card"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 687, 0x1f48e, 0x0, "gem"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1196, 0x2696, 0x0, "scales"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 839, 0x1f527, 0x0, "wrench"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 840, 0x1f528, 0x0, "hammer"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1193, 0x2692, 0x0, "hammer_pick"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1089, 0x1f6e0, 0x0, "tools"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1213, 0x26cf, 0x0, "pick"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 841, 0x1f529, 0x0, "nut_and_bolt"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1198, 0x2699, 0x0, "gear"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1215, 0x26d3, 0x0, "chains"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 843, 0x1f52b, 0x0, "gun"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 708, 0x1f4a3, 0x0, "bomb"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 842, 0x1f52a, 0x0, "knife"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 923, 0x1f5e1, 0x0, "dagger"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1195, 0x2694, 0x0, "crossed_swords"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1090, 0x1f6e1, 0x0, "shield"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1057, 0x1f6ac, 0x0, "smoking"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1164, 0x2620, 0x0, "skull_crossbones"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1205, 0x26b0, 0x0, "coffin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1206, 0x26b1, 0x0, "urn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 543, 0x1f3fa, 0x0, "amphora"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 846, 0x1f52e, 0x0, "crystal_ball"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 799, 0x1f4ff, 0x0, "prayer_beads"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 681, 0x1f488, 0x0, "barber"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1197, 0x2697, 0x0, "alembic"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 845, 0x1f52d, 0x0, "telescope"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 844, 0x1f52c, 0x0, "microscope"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 894, 0x1f573, 0x0, "hole"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 683, 0x1f48a, 0x0, "pill"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 682, 0x1f489, 0x0, "syringe"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 336, 0x1f321, 0x0, "thermometer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 540, 0x1f3f7, 0x0, "label"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 822, 0x1f516, 0x0, "bookmark"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1074, 0x1f6bd, 0x0, "toilet"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1076, 0x1f6bf, 0x0, "shower"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1078, 0x1f6c1, 0x0, "bathtub"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 817, 0x1f511, 0x0, "key"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 921, 0x1f5dd, 0x0, "key2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1083, 0x1f6cb, 0x0, "couch"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1084, 0x1f6cc, 0x0, "sleeping_accommodation"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1087, 0x1f6cf, 0x0, "bed"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1055, 0x1f6aa, 0x0, "door"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1086, 0x1f6ce, 0x0, "bellhop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 913, 0x1f5bc, 0x0, "frame_photo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 927, 0x1f5fa, 0x0, "map"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1220, 0x26f1, 0x0, "beach_umbrella"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 932, 0x1f5ff, 0x0, "moyai"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1085, 0x1f6cd, 0x0, "shopping_bags"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 437, 0x1f388, 0x0, "balloon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 444, 0x1f38f, 0x0, "flags"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 429, 0x1f380, 0x0, "ribbon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 430, 0x1f381, 0x0, "gift"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 439, 0x1f38a, 0x0, "confetti_ball"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 438, 0x1f389, 0x0, "tada"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 443, 0x1f38e, 0x0, "dolls"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 445, 0x1f390, 0x0, "wind_chime"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 441, 0x1f38c, 0x0, "crossed_flags"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 534, 0x1f3ee, 0x0, "izakaya_lantern"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1233, 0x2709, 0x0, "envelope"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 778, 0x1f4e9, 0x0, "envelope_with_arrow"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 777, 0x1f4e8, 0x0, "incoming_envelope"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 776, 0x1f4e7, 0x0, "e-mail"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 685, 0x1f48c, 0x0, "love_letter"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 783, 0x1f4ee, 0x0, "postbox"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 779, 0x1f4ea, 0x0, "mailbox_closed"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 780, 0x1f4eb, 0x0, "mailbox"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 781, 0x1f4ec, 0x0, "mailbox_with_mail"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 782, 0x1f4ed, 0x0, "mailbox_with_no_mail"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 775, 0x1f4e6, 0x0, "package"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 784, 0x1f4ef, 0x0, "postal_horn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 774, 0x1f4e5, 0x0, "inbox_tray"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 773, 0x1f4e4, 0x0, "outbox_tray"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 765, 0x1f4dc, 0x0, "scroll"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 740, 0x1f4c3, 0x0, "page_with_curl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 754, 0x1f4d1, 0x0, "bookmark_tabs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 747, 0x1f4ca, 0x0, "bar_chart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 745, 0x1f4c8, 0x0, "chart_with_upwards_trend"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 746, 0x1f4c9, 0x0, "chart_with_downwards_trend"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 741, 0x1f4c4, 0x0, "page_facing_up"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 742, 0x1f4c5, 0x0, "date"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 743, 0x1f4c6, 0x0, "calendar"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 919, 0x1f5d3, 0x0, "calendar_spiral"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 744, 0x1f4c7, 0x0, "card_index"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 915, 0x1f5c3, 0x0, "card_box"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 926, 0x1f5f3, 0x0, "ballot_box"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 916, 0x1f5c4, 0x0, "file_cabinet"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 748, 0x1f4cb, 0x0, "clipboard"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 918, 0x1f5d2, 0x0, "notepad_spiral"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 738, 0x1f4c1, 0x0, "file_folder"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 739, 0x1f4c2, 0x0, "open_file_folder"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 914, 0x1f5c2, 0x0, "dividers"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 922, 0x1f5de, 0x0, "newspaper2"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 785, 0x1f4f0, 0x0, "newspaper"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 756, 0x1f4d3, 0x0, "notebook"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 758, 0x1f4d5, 0x0, "closed_book"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 760, 0x1f4d7, 0x0, "green_book"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 761, 0x1f4d8, 0x0, "blue_book"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 762, 0x1f4d9, 0x0, "orange_book"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 757, 0x1f4d4, 0x0, "notebook_with_decorative_cover"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 755, 0x1f4d2, 0x0, "ledger"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 763, 0x1f4da, 0x0, "books"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 759, 0x1f4d6, 0x0, "book"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 823, 0x1f517, 0x0, "link"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 751, 0x1f4ce, 0x0, "paperclip"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 901, 0x1f587, 0x0, "paperclips"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1230, 0x2702, 0x0, "scissors"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 753, 0x1f4d0, 0x0, "triangular_ruler"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 752, 0x1f4cf, 0x0, "straight_ruler"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 749, 0x1f4cc, 0x0, "pushpin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 750, 0x1f4cd, 0x0, "round_pushpin"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1054, 0x1f6a9, 0x0, "triangular_flag_on_post"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 537, 0x1f3f3, 0x0, "flag_white"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 538, 0x1f3f4, 0x0, "flag_black"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 816, 0x1f510, 0x0, "closed_lock_with_key"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 818, 0x1f512, 0x0, "lock"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 819, 0x1f513, 0x0, "unlock"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 815, 0x1f50f, 0x0, "lock_with_ink_pen"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 902, 0x1f58a, 0x0, "pen_ballpoint"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 903, 0x1f58b, 0x0, "pen_fountain"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1239, 0x2712, 0x0, "black_nib"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 766, 0x1f4dd, 0x0, "pencil"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 1238, 0x270f, 0x0, "pencil2"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 905, 0x1f58d, 0x0, "crayon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 904, 0x1f58c, 0x0, "paintbrush"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 813, 0x1f50d, 0x0, "mag"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("objects", 814, 0x1f50e, 0x0, "mag_right"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1256, 0x2764, 0x0, "heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 700, 0x1f49b, 0x0, "yellow_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 699, 0x1f49a, 0x0, "green_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 698, 0x1f499, 0x0, "blue_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 701, 0x1f49c, 0x0, "purple_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 693, 0x1f494, 0x0, "broken_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1255, 0x2763, 0x0, "heart_exclamation"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 694, 0x1f495, 0x0, "two_hearts"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 703, 0x1f49e, 0x0, "revolving_hearts"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 692, 0x1f493, 0x0, "heartbeat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 696, 0x1f497, 0x0, "heartpulse"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 695, 0x1f496, 0x0, "sparkling_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 697, 0x1f498, 0x0, "cupid"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 702, 0x1f49d, 0x0, "gift_heart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 704, 0x1f49f, 0x0, "heart_decoration"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1169, 0x262e, 0x0, "peace"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1242, 0x271d, 0x0, "cross"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1168, 0x262a, 0x0, "star_and_crescent"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 862, 0x1f549, 0x0, "om_symbol"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1171, 0x2638, 0x0, "wheel_of_dharma"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1243, 0x2721, 0x0, "star_of_david"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 847, 0x1f52f, 0x0, "six_pointed_star"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 867, 0x1f54e, 0x0, "menorah"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1170, 0x262f, 0x0, "yin_yang"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1167, 0x2626, 0x0, "orthodox_cross"));
EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1088, 0x1f6d0, 0x0, "place_of_worship"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1212, 0x26ce, 0x0, "ophiuchus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1174, 0x2648, 0x0, "aries"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1175, 0x2649, 0x0, "taurus"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1176, 0x264a, 0x0, "gemini"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1177, 0x264b, 0x0, "cancer"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1178, 0x264c, 0x0, "leo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1179, 0x264d, 0x0, "virgo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1180, 0x264e, 0x0, "libra"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1181, 0x264f, 0x0, "scorpius"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1182, 0x2650, 0x0, "sagittarius"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1183, 0x2651, 0x0, "capricorn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1184, 0x2652, 0x0, "aquarius"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1185, 0x2653, 0x0, "pisces"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 24, 0x1f194, 0x0, "id"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1199, 0x269b, 0x0, "atom"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 293, 0x1f233, 0x0, "u7a7a"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 299, 0x1f239, 0x0, "u5272"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1165, 0x2622, 0x0, "radioactive"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1166, 0x2623, 0x0, "biohazard"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 789, 0x1f4f4, 0x0, "mobile_phone_off"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 788, 0x1f4f3, 0x0, "vibration_mode"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 296, 0x1f236, 0x0, "u6709"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 290, 0x1f21a, 0x0, "u7121"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 298, 0x1f238, 0x0, "u7533"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 300, 0x1f23a, 0x0, "u55b6"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 297, 0x1f237, 0x0, "u6708"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1246, 0x2734, 0x0, "eight_pointed_black_star"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 30, 0x1f19a, 0x0, "vs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 302, 0x1f251, 0x0, "accept"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 719, 0x1f4ae, 0x0, "white_flower"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 301, 0x1f250, 0x0, "ideograph_advantage"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1275, 0x3299, 0x0, "secret"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1274, 0x3297, 0x0, "congratulations"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 294, 0x1f234, 0x0, "u5408"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 295, 0x1f235, 0x0, "u6e80"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 292, 0x1f232, 0x0, "u7981"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 16, 0x1f170, 0x0, "a"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 17, 0x1f171, 0x0, "b"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 20, 0x1f18e, 0x0, "ab"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 21, 0x1f191, 0x0, "cl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 18, 0x1f17e, 0x0, "o2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 28, 0x1f198, 0x0, "sos"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1216, 0x26d4, 0x0, "no_entry"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 764, 0x1f4db, 0x0, "name_badge"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1056, 0x1f6ab, 0x0, "no_entry_sign"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1249, 0x274c, 0x0, "x"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1271, 0x2b55, 0x0, "o"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 707, 0x1f4a2, 0x0, "anger"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1190, 0x2668, 0x0, "hotsprings"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1068, 0x1f6b7, 0x0, "no_pedestrians"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1060, 0x1f6af, 0x0, "do_not_litter"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1064, 0x1f6b3, 0x0, "no_bicycles"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1062, 0x1f6b1, 0x0, "non-potable_water"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 830, 0x1f51e, 0x0, "underage"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 790, 0x1f4f5, 0x0, "no_mobile_phones"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1254, 0x2757, 0x0, "exclamation"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1253, 0x2755, 0x0, "grey_exclamation"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1251, 0x2753, 0x0, "question"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1252, 0x2754, 0x0, "grey_question"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1115, 0x203c, 0x0, "bangbang"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1116, 0x2049, 0x0, "interrobang"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 720, 0x1f4af, 0x0, "100"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 805, 0x1f505, 0x0, "low_brightness"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 806, 0x1f506, 0x0, "high_brightness"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 849, 0x1f531, 0x0, "trident"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1200, 0x269c, 0x0, "fleur-de-lis"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1273, 0x303d, 0x0, "part_alternation_mark"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1201, 0x26a0, 0x0, "warning"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1069, 0x1f6b8, 0x0, "children_crossing"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 848, 0x1f530, 0x0, "beginner"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1191, 0x267b, 0x0, "recycle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 291, 0x1f22f, 0x0, "u6307"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 730, 0x1f4b9, 0x0, "chart"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1248, 0x2747, 0x0, "sparkle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1245, 0x2733, 0x0, "eight_spoked_asterisk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1250, 0x274e, 0x0, "negative_squared_cross_mark"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1231, 0x2705, 0x0, "white_check_mark"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 705, 0x1f4a0, 0x0, "diamond_shape_with_a_dot_inside"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 303, 0x1f300, 0x0, "cyclone"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1262, 0x27bf, 0x0, "loop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 319, 0x1f310, 0x0, "globe_with_meridians"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1144, 0x24c2, 0x0, "m"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 527, 0x1f3e7, 0x0, "atm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 289, 0x1f202, 0x0, "sa"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1079, 0x1f6c2, 0x0, "passport_control"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1080, 0x1f6c3, 0x0, "customs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1081, 0x1f6c4, 0x0, "baggage_claim"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1082, 0x1f6c5, 0x0, "left_luggage"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1192, 0x267f, 0x0, "wheelchair"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1058, 0x1f6ad, 0x0, "no_smoking"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1075, 0x1f6be, 0x0, "wc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 19, 0x1f17f, 0x0, "parking"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1061, 0x1f6b0, 0x0, "potable_water"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1070, 0x1f6b9, 0x0, "mens"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1071, 0x1f6ba, 0x0, "womens"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1073, 0x1f6bc, 0x0, "baby_symbol"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1072, 0x1f6bb, 0x0, "restroom"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1059, 0x1f6ae, 0x0, "put_litter_in_its_place"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 462, 0x1f3a6, 0x0, "cinema"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 791, 0x1f4f6, 0x0, "signal_strength"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 288, 0x1f201, 0x0, "koko"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 26, 0x1f196, 0x0, "ng"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 27, 0x1f197, 0x0, "ok"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 29, 0x1f199, 0x0, "up"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 22, 0x1f192, 0x0, "cool"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 25, 0x1f195, 0x0, "new"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 23, 0x1f193, 0x0, "free"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 2, 0x0030, 0x20e3, "zero"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 3, 0x0031, 0x20e3, "one"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 4, 0x0032, 0x20e3, "two"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 5, 0x0033, 0x20e3, "three"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 6, 0x0034, 0x20e3, "four"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 7, 0x0035, 0x20e3, "five"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 8, 0x0036, 0x20e3, "six"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 9, 0x0037, 0x20e3, "seven"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 10, 0x0038, 0x20e3, "eight"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 11, 0x0039, 0x20e3, "nine"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 831, 0x1f51f, 0x0, "ten"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 834, 0x1f522, 0x0, "1234"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1147, 0x25b6, 0x0, "arrow_forward"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1141, 0x23f8, 0x0, "pause_button"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1136, 0x23ef, 0x0, "play_pause"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1142, 0x23f9, 0x0, "stop_button"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1143, 0x23fa, 0x0, "record_button"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1134, 0x23ed, 0x0, "track_next"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1135, 0x23ee, 0x0, "track_previous"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1130, 0x23e9, 0x0, "fast_forward"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1131, 0x23ea, 0x0, "rewind"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 800, 0x1f500, 0x0, "twisted_rightwards_arrows"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 801, 0x1f501, 0x0, "repeat"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 802, 0x1f502, 0x0, "repeat_one"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1148, 0x25c0, 0x0, "arrow_backward"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 860, 0x1f53c, 0x0, "arrow_up_small"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 861, 0x1f53d, 0x0, "arrow_down_small"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1132, 0x23eb, 0x0, "arrow_double_up"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1133, 0x23ec, 0x0, "arrow_double_down"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1260, 0x27a1, 0x0, "arrow_right"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1265, 0x2b05, 0x0, "arrow_left"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1266, 0x2b06, 0x0, "arrow_up"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1267, 0x2b07, 0x0, "arrow_down"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1122, 0x2197, 0x0, "arrow_upper_right"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1123, 0x2198, 0x0, "arrow_lower_right"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1124, 0x2199, 0x0, "arrow_lower_left"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1121, 0x2196, 0x0, "arrow_upper_left"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1120, 0x2195, 0x0, "arrow_up_down"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1119, 0x2194, 0x0, "left_right_arrow"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 804, 0x1f504, 0x0, "arrows_counterclockwise"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1126, 0x21aa, 0x0, "arrow_right_hook"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1125, 0x21a9, 0x0, "leftwards_arrow_with_hook"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1263, 0x2934, 0x0, "arrow_heading_up"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1264, 0x2935, 0x0, "arrow_heading_down"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 0, 0x0023, 0x20e3, "hash"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1, 0x002a, 0x20e3, "asterisk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1118, 0x2139, 0x0, "information_source"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 836, 0x1f524, 0x0, "abc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 833, 0x1f521, 0x0, "abcd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 832, 0x1f520, 0x0, "capital_abcd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 835, 0x1f523, 0x0, "symbols"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 477, 0x1f3b5, 0x0, "musical_note"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 478, 0x1f3b6, 0x0, "notes"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1272, 0x3030, 0x0, "wavy_dash"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1261, 0x27b0, 0x0, "curly_loop"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1240, 0x2714, 0x0, "heavy_check_mark"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 803, 0x1f503, 0x0, "arrows_clockwise"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1257, 0x2795, 0x0, "heavy_plus_sign"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1258, 0x2796, 0x0, "heavy_minus_sign"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1259, 0x2797, 0x0, "heavy_division_sign"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1241, 0x2716, 0x0, "heavy_multiplication_x"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 723, 0x1f4b2, 0x0, "heavy_dollar_sign"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 722, 0x1f4b1, 0x0, "currency_exchange"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 12, 0x00a9, 0x0, "copyright"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 13, 0x00ae, 0x0, "registered"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1117, 0x2122, 0x0, "tm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 826, 0x1f51a, 0x0, "end"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 825, 0x1f519, 0x0, "back"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 827, 0x1f51b, 0x0, "on"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 829, 0x1f51d, 0x0, "top"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 828, 0x1f51c, 0x0, "soon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1159, 0x2611, 0x0, "ballot_box_with_check"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 824, 0x1f518, 0x0, "radio_button"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1203, 0x26aa, 0x0, "white_circle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1204, 0x26ab, 0x0, "black_circle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 852, 0x1f534, 0x0, "red_circle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 853, 0x1f535, 0x0, "large_blue_circle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 856, 0x1f538, 0x0, "small_orange_diamond"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 857, 0x1f539, 0x0, "small_blue_diamond"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 854, 0x1f536, 0x0, "large_orange_diamond"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 855, 0x1f537, 0x0, "large_blue_diamond"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 858, 0x1f53a, 0x0, "small_red_triangle"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1145, 0x25aa, 0x0, "black_small_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1146, 0x25ab, 0x0, "white_small_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1268, 0x2b1b, 0x0, "black_large_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1269, 0x2b1c, 0x0, "white_large_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 859, 0x1f53b, 0x0, "small_red_triangle_down"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1150, 0x25fc, 0x0, "black_medium_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1149, 0x25fb, 0x0, "white_medium_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1152, 0x25fe, 0x0, "black_medium_small_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1151, 0x25fd, 0x0, "white_medium_small_square"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 850, 0x1f532, 0x0, "black_square_button"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 851, 0x1f533, 0x0, "white_square_button"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 808, 0x1f508, 0x0, "speaker"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 809, 0x1f509, 0x0, "sound"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 810, 0x1f50a, 0x0, "loud_sound"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 807, 0x1f507, 0x0, "mute"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 772, 0x1f4e3, 0x0, "mega"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 771, 0x1f4e2, 0x0, "loudspeaker"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 820, 0x1f514, 0x0, "bell"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 821, 0x1f515, 0x0, "no_bell"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 15, 0x1f0cf, 0x0, "black_joker"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 14, 0x1f004, 0x0, "mahjong"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1186, 0x2660, 0x0, "spades"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1187, 0x2663, 0x0, "clubs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1188, 0x2665, 0x0, "hearts"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 1189, 0x2666, 0x0, "diamonds"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 476, 0x1f3b4, 0x0, "flower_playing_cards"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 718, 0x1f4ad, 0x0, "thought_balloon"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 925, 0x1f5ef, 0x0, "anger_right"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 717, 0x1f4ac, 0x0, "speech_balloon"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 868, 0x1f550, 0x0, "clock1"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 869, 0x1f551, 0x0, "clock2"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 870, 0x1f552, 0x0, "clock3"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 871, 0x1f553, 0x0, "clock4"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 872, 0x1f554, 0x0, "clock5"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 873, 0x1f555, 0x0, "clock6"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 874, 0x1f556, 0x0, "clock7"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 875, 0x1f557, 0x0, "clock8"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 876, 0x1f558, 0x0, "clock9"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 877, 0x1f559, 0x0, "clock10"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 878, 0x1f55a, 0x0, "clock11"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 879, 0x1f55b, 0x0, "clock12"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 880, 0x1f55c, 0x0, "clock130"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 881, 0x1f55d, 0x0, "clock230"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 882, 0x1f55e, 0x0, "clock330"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 883, 0x1f55f, 0x0, "clock430"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 884, 0x1f560, 0x0, "clock530"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 885, 0x1f561, 0x0, "clock630"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 886, 0x1f562, 0x0, "clock730"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 887, 0x1f563, 0x0, "clock830"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 888, 0x1f564, 0x0, "clock930"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 889, 0x1f565, 0x0, "clock1030"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 890, 0x1f566, 0x0, "clock1130"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 891, 0x1f567, 0x0, "clock1230"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("symbols", 610, 0x1f441, 0x1f5e8, "eye_in_speech_bubble"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 31, 0x1f1e6, 0x1f1e8, "flag_ac"));
}
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 34, 0x1f1e6, 0x1f1eb, "flag_af"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 37, 0x1f1e6, 0x1f1f1, "flag_al"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 95, 0x1f1e9, 0x1f1ff, "flag_dz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 32, 0x1f1e6, 0x1f1e9, "flag_ad"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 39, 0x1f1e6, 0x1f1f4, "flag_ao"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 36, 0x1f1e6, 0x1f1ee, "flag_ai"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 35, 0x1f1e6, 0x1f1ec, "flag_ag"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 41, 0x1f1e6, 0x1f1f7, "flag_ar"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 38, 0x1f1e6, 0x1f1f2, "flag_am"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 45, 0x1f1e6, 0x1f1fc, "flag_aw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 44, 0x1f1e6, 0x1f1fa, "flag_au"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 43, 0x1f1e6, 0x1f1f9, "flag_at"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 47, 0x1f1e6, 0x1f1ff, "flag_az"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 63, 0x1f1e7, 0x1f1f8, "flag_bs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 54, 0x1f1e7, 0x1f1ed, "flag_bh"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 50, 0x1f1e7, 0x1f1e9, "flag_bd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 49, 0x1f1e7, 0x1f1e7, "flag_bb"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 67, 0x1f1e7, 0x1f1fe, "flag_by"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 51, 0x1f1e7, 0x1f1ea, "flag_be"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 68, 0x1f1e7, 0x1f1ff, "flag_bz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 56, 0x1f1e7, 0x1f1ef, "flag_bj"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 58, 0x1f1e7, 0x1f1f2, "flag_bm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 64, 0x1f1e7, 0x1f1f9, "flag_bt"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 60, 0x1f1e7, 0x1f1f4, "flag_bo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 48, 0x1f1e7, 0x1f1e6, "flag_ba"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 66, 0x1f1e7, 0x1f1fc, "flag_bw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 62, 0x1f1e7, 0x1f1f7, "flag_br"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 59, 0x1f1e7, 0x1f1f3, "flag_bn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 53, 0x1f1e7, 0x1f1ec, "flag_bg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 52, 0x1f1e7, 0x1f1eb, "flag_bf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 55, 0x1f1e7, 0x1f1ee, "flag_bi"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 84, 0x1f1e8, 0x1f1fb, "flag_cv"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 153, 0x1f1f0, 0x1f1ed, "flag_kh"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 78, 0x1f1e8, 0x1f1f2, "flag_cm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 69, 0x1f1e8, 0x1f1e6, "flag_ca"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 160, 0x1f1f0, 0x1f1fe, "flag_ky"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 72, 0x1f1e8, 0x1f1eb, "flag_cf"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 252, 0x1f1f9, 0x1f1e9, "flag_td"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 77, 0x1f1e8, 0x1f1f1, "flag_cl"));
} //EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 79, 0x1f1e8, 0x1f1f3, "flag_cn"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 80, 0x1f1e8, 0x1f1f4, "flag_co"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 155, 0x1f1f0, 0x1f1f2, "flag_km"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 73, 0x1f1e8, 0x1f1ec, "flag_cg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 71, 0x1f1e8, 0x1f1e9, "flag_cd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 82, 0x1f1e8, 0x1f1f7, "flag_cr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 133, 0x1f1ed, 0x1f1f7, "flag_hr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 83, 0x1f1e8, 0x1f1fa, "flag_cu"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 87, 0x1f1e8, 0x1f1fe, "flag_cy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 88, 0x1f1e8, 0x1f1ff, "flag_cz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 92, 0x1f1e9, 0x1f1f0, "flag_dk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 91, 0x1f1e9, 0x1f1ef, "flag_dj"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 93, 0x1f1e9, 0x1f1f2, "flag_dm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 94, 0x1f1e9, 0x1f1f4, "flag_do"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 97, 0x1f1ea, 0x1f1e8, "flag_ec"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 99, 0x1f1ea, 0x1f1ec, "flag_eg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 246, 0x1f1f8, 0x1f1fb, "flag_sv"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 123, 0x1f1ec, 0x1f1f6, "flag_gq"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 101, 0x1f1ea, 0x1f1f7, "flag_er"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 98, 0x1f1ea, 0x1f1ea, "flag_ee"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 103, 0x1f1ea, 0x1f1f9, "flag_et"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 107, 0x1f1eb, 0x1f1f0, "flag_fk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 109, 0x1f1eb, 0x1f1f4, "flag_fo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 106, 0x1f1eb, 0x1f1ef, "flag_fj"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 105, 0x1f1eb, 0x1f1ee, "flag_fi"));
} //EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 110, 0x1f1eb, 0x1f1f7, "flag_fr"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 211, 0x1f1f5, 0x1f1eb, "flag_pf"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 111, 0x1f1ec, 0x1f1e6, "flag_ga"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 120, 0x1f1ec, 0x1f1f2, "flag_gm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 114, 0x1f1ec, 0x1f1ea, "flag_ge"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 89, 0x1f1e9, 0x1f1ea, "flag_de"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 117, 0x1f1ec, 0x1f1ed, "flag_gh"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 118, 0x1f1ec, 0x1f1ee, "flag_gi"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 124, 0x1f1ec, 0x1f1f7, "flag_gr"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 119, 0x1f1ec, 0x1f1f1, "flag_gl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 113, 0x1f1ec, 0x1f1e9, "flag_gd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 127, 0x1f1ec, 0x1f1fa, "flag_gu"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 126, 0x1f1ec, 0x1f1f9, "flag_gt"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 121, 0x1f1ec, 0x1f1f3, "flag_gn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 128, 0x1f1ec, 0x1f1fc, "flag_gw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 129, 0x1f1ec, 0x1f1fe, "flag_gy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 134, 0x1f1ed, 0x1f1f9, "flag_ht"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 132, 0x1f1ed, 0x1f1f3, "flag_hn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 130, 0x1f1ed, 0x1f1f0, "flag_hk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 135, 0x1f1ed, 0x1f1fa, "flag_hu"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 145, 0x1f1ee, 0x1f1f8, "flag_is"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 141, 0x1f1ee, 0x1f1f3, "flag_in"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 137, 0x1f1ee, 0x1f1e9, "flag_id"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 144, 0x1f1ee, 0x1f1f7, "flag_ir"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 143, 0x1f1ee, 0x1f1f6, "flag_iq"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 138, 0x1f1ee, 0x1f1ea, "flag_ie"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 139, 0x1f1ee, 0x1f1f1, "flag_il"));
} //EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 146, 0x1f1ee, 0x1f1f9, "flag_it"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 75, 0x1f1e8, 0x1f1ee, "flag_ci"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 148, 0x1f1ef, 0x1f1f2, "flag_jm"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 150, 0x1f1ef, 0x1f1f5, "flag_jp"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 147, 0x1f1ef, 0x1f1ea, "flag_je"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 149, 0x1f1ef, 0x1f1f4, "flag_jo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 161, 0x1f1f0, 0x1f1ff, "flag_kz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 151, 0x1f1f0, 0x1f1ea, "flag_ke"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 154, 0x1f1f0, 0x1f1ee, "flag_ki"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 282, 0x1f1fd, 0x1f1f0, "flag_xk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 159, 0x1f1f0, 0x1f1fc, "flag_kw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 152, 0x1f1f0, 0x1f1ec, "flag_kg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 162, 0x1f1f1, 0x1f1e6, "flag_la"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 171, 0x1f1f1, 0x1f1fb, "flag_lv"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 163, 0x1f1f1, 0x1f1e7, "flag_lb"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 168, 0x1f1f1, 0x1f1f8, "flag_ls"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 167, 0x1f1f1, 0x1f1f7, "flag_lr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 172, 0x1f1f1, 0x1f1fe, "flag_ly"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 165, 0x1f1f1, 0x1f1ee, "flag_li"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 169, 0x1f1f1, 0x1f1f9, "flag_lt"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 170, 0x1f1f1, 0x1f1fa, "flag_lu"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 184, 0x1f1f2, 0x1f1f4, "flag_mo"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 180, 0x1f1f2, 0x1f1f0, "flag_mk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 178, 0x1f1f2, 0x1f1ec, "flag_mg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 192, 0x1f1f2, 0x1f1fc, "flag_mw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 194, 0x1f1f2, 0x1f1fe, "flag_my"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 191, 0x1f1f2, 0x1f1fb, "flag_mv"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 181, 0x1f1f2, 0x1f1f1, "flag_ml"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 189, 0x1f1f2, 0x1f1f9, "flag_mt"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 179, 0x1f1f2, 0x1f1ed, "flag_mh"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 187, 0x1f1f2, 0x1f1f7, "flag_mr"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 190, 0x1f1f2, 0x1f1fa, "flag_mu"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 193, 0x1f1f2, 0x1f1fd, "flag_mx"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 108, 0x1f1eb, 0x1f1f2, "flag_fm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 175, 0x1f1f2, 0x1f1e9, "flag_md"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 174, 0x1f1f2, 0x1f1e8, "flag_mc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 183, 0x1f1f2, 0x1f1f3, "flag_mn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 176, 0x1f1f2, 0x1f1ea, "flag_me"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 188, 0x1f1f2, 0x1f1f8, "flag_ms"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 173, 0x1f1f2, 0x1f1e6, "flag_ma"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 195, 0x1f1f2, 0x1f1ff, "flag_mz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 182, 0x1f1f2, 0x1f1f2, "flag_mm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 196, 0x1f1f3, 0x1f1e6, "flag_na"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 205, 0x1f1f3, 0x1f1f7, "flag_nr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 204, 0x1f1f3, 0x1f1f5, "flag_np"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 202, 0x1f1f3, 0x1f1f1, "flag_nl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 197, 0x1f1f3, 0x1f1e8, "flag_nc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 207, 0x1f1f3, 0x1f1ff, "flag_nz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 201, 0x1f1f3, 0x1f1ee, "flag_ni"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 198, 0x1f1f3, 0x1f1ea, "flag_ne"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 200, 0x1f1f3, 0x1f1ec, "flag_ng"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 206, 0x1f1f3, 0x1f1fa, "flag_nu"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 157, 0x1f1f0, 0x1f1f5, "flag_kp"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 203, 0x1f1f3, 0x1f1f4, "flag_no"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 208, 0x1f1f4, 0x1f1f2, "flag_om"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 214, 0x1f1f5, 0x1f1f0, "flag_pk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 221, 0x1f1f5, 0x1f1fc, "flag_pw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 219, 0x1f1f5, 0x1f1f8, "flag_ps"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 209, 0x1f1f5, 0x1f1e6, "flag_pa"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 212, 0x1f1f5, 0x1f1ec, "flag_pg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 222, 0x1f1f5, 0x1f1fe, "flag_py"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 210, 0x1f1f5, 0x1f1ea, "flag_pe"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 213, 0x1f1f5, 0x1f1ed, "flag_ph"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 215, 0x1f1f5, 0x1f1f1, "flag_pl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 220, 0x1f1f5, 0x1f1f9, "flag_pt"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 218, 0x1f1f5, 0x1f1f7, "flag_pr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 223, 0x1f1f6, 0x1f1e6, "flag_qa"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 225, 0x1f1f7, 0x1f1f4, "flag_ro"));
} //EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 227, 0x1f1f7, 0x1f1fa, "flag_ru"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 228, 0x1f1f7, 0x1f1fc, "flag_rw"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 235, 0x1f1f8, 0x1f1ed, "flag_sh"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 156, 0x1f1f0, 0x1f1f3, "flag_kn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 164, 0x1f1f1, 0x1f1e8, "flag_lc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 274, 0x1f1fb, 0x1f1e8, "flag_vc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 281, 0x1f1fc, 0x1f1f8, "flag_ws"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 240, 0x1f1f8, 0x1f1f2, "flag_sm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 245, 0x1f1f8, 0x1f1f9, "flag_st"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 229, 0x1f1f8, 0x1f1e6, "flag_sa"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 241, 0x1f1f8, 0x1f1f3, "flag_sn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 226, 0x1f1f7, 0x1f1f8, "flag_rs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 231, 0x1f1f8, 0x1f1e8, "flag_sc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 239, 0x1f1f8, 0x1f1f1, "flag_sl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 234, 0x1f1f8, 0x1f1ec, "flag_sg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 238, 0x1f1f8, 0x1f1f0, "flag_sk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 236, 0x1f1f8, 0x1f1ee, "flag_si"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 230, 0x1f1f8, 0x1f1e7, "flag_sb"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 242, 0x1f1f8, 0x1f1f4, "flag_so"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 285, 0x1f1ff, 0x1f1e6, "flag_za"));
} //EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 158, 0x1f1f0, 0x1f1f7, "flag_kr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 102, 0x1f1ea, 0x1f1f8, "flag_es"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 166, 0x1f1f1, 0x1f1f0, "flag_lk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 232, 0x1f1f8, 0x1f1e9, "flag_sd"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 243, 0x1f1f8, 0x1f1f7, "flag_sr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 249, 0x1f1f8, 0x1f1ff, "flag_sz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 233, 0x1f1f8, 0x1f1ea, "flag_se"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 74, 0x1f1e8, 0x1f1ed, "flag_ch"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 248, 0x1f1f8, 0x1f1fe, "flag_sy"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 265, 0x1f1f9, 0x1f1fc, "flag_tw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 256, 0x1f1f9, 0x1f1ef, "flag_tj"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 266, 0x1f1f9, 0x1f1ff, "flag_tz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 255, 0x1f1f9, 0x1f1ed, "flag_th"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 258, 0x1f1f9, 0x1f1f1, "flag_tl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 254, 0x1f1f9, 0x1f1ec, "flag_tg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 261, 0x1f1f9, 0x1f1f4, "flag_to"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 263, 0x1f1f9, 0x1f1f9, "flag_tt"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 260, 0x1f1f9, 0x1f1f3, "flag_tn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 262, 0x1f1f9, 0x1f1f7, "flag_tr"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 259, 0x1f1f9, 0x1f1f2, "flag_tm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 264, 0x1f1f9, 0x1f1fb, "flag_tv"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 268, 0x1f1fa, 0x1f1ec, "flag_ug"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 267, 0x1f1fa, 0x1f1e6, "flag_ua"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 33, 0x1f1e6, 0x1f1ea, "flag_ae"));
} //EXCLUDE_EMOJI_MAC_10_9
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 112, 0x1f1ec, 0x1f1e7, "flag_gb"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 270, 0x1f1fa, 0x1f1f8, "flag_us"));
EXCLUDE_EMOJI_MAC_10_9
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 277, 0x1f1fb, 0x1f1ee, "flag_vi"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 271, 0x1f1fa, 0x1f1fe, "flag_uy"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 272, 0x1f1fa, 0x1f1ff, "flag_uz"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 279, 0x1f1fb, 0x1f1fa, "flag_vu"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 273, 0x1f1fb, 0x1f1e6, "flag_va"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 275, 0x1f1fb, 0x1f1ea, "flag_ve"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 278, 0x1f1fb, 0x1f1f3, "flag_vn"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 280, 0x1f1fc, 0x1f1eb, "flag_wf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 100, 0x1f1ea, 0x1f1ed, "flag_eh"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 283, 0x1f1fe, 0x1f1ea, "flag_ye"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 286, 0x1f1ff, 0x1f1f2, "flag_zm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 287, 0x1f1ff, 0x1f1fc, "flag_zw"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 224, 0x1f1f7, 0x1f1ea, "flag_re"));
EXCLUDE_EMOJI_MAC_10_10
{
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 46, 0x1f1e6, 0x1f1fd, "flag_ax"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 250, 0x1f1f9, 0x1f1e6, "flag_ta"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 142, 0x1f1ee, 0x1f1f4, "flag_io"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 61, 0x1f1e7, 0x1f1f6, "flag_bq"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 86, 0x1f1e8, 0x1f1fd, "flag_cx"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 70, 0x1f1e8, 0x1f1e8, "flag_cc"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 116, 0x1f1ec, 0x1f1ec, "flag_gg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 140, 0x1f1ee, 0x1f1f2, "flag_im"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 284, 0x1f1fe, 0x1f1f9, "flag_yt"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 199, 0x1f1f3, 0x1f1eb, "flag_nf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 217, 0x1f1f5, 0x1f1f3, "flag_pn"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 57, 0x1f1e7, 0x1f1f1, "flag_bl"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 216, 0x1f1f5, 0x1f1f2, "flag_pm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 125, 0x1f1ec, 0x1f1f8, "flag_gs"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 257, 0x1f1f9, 0x1f1f0, "flag_tk"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 65, 0x1f1e7, 0x1f1fb, "flag_bv"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 131, 0x1f1ed, 0x1f1f2, "flag_hm"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 237, 0x1f1f8, 0x1f1ef, "flag_sj"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 269, 0x1f1fa, 0x1f1f2, "flag_um"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 136, 0x1f1ee, 0x1f1e8, "flag_ic"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 96, 0x1f1ea, 0x1f1e6, "flag_ea"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 81, 0x1f1e8, 0x1f1f5, "flag_cp"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 90, 0x1f1e9, 0x1f1ec, "flag_dg"));
}
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 42, 0x1f1e6, 0x1f1f8, "flag_as"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 40, 0x1f1e6, 0x1f1f6, "flag_aq"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 276, 0x1f1fb, 0x1f1ec, "flag_vg"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 76, 0x1f1e8, 0x1f1f0, "flag_ck"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 85, 0x1f1e8, 0x1f1fc, "flag_cw"));
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 104, 0x1f1ea, 0x1f1fa, "flag_eu"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 115, 0x1f1ec, 0x1f1eb, "flag_gf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 253, 0x1f1f9, 0x1f1eb, "flag_tf"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 122, 0x1f1ec, 0x1f1f5, "flag_gp"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 186, 0x1f1f2, 0x1f1f6, "flag_mq"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 185, 0x1f1f2, 0x1f1f5, "flag_mp"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 247, 0x1f1f8, 0x1f1fd, "flag_sx"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 244, 0x1f1f8, 0x1f1f8, "flag_ss"));
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 251, 0x1f1f9, 0x1f1e8, "flag_tc"));
} //EXCLUDE_EMOJI_MAC_10_9
EXCLUDE_EMOJI_MAC_10_10
EmojiIndexByOrder_.emplace_back(std::make_shared<EmojiRecord>("flags", 177, 0x1f1f2, 0x1f1eb, "flag_mf"));