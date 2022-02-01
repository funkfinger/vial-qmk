VIA_ENABLE = yes
VIAL_ENABLE = yes
MOUSEKEY_ENABLE = no

QMK_SETTINGS = no
TAP_DANCE_ENABLE = no
COMBO_ENABLE = no

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif
