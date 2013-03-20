/**
 * @file
 * @brief
 *
 * @author  Anton Kozlov
 * @date    14.03.2013
 */

#include <drivers/keyboard.h>
#include <drivers/input/input_dev.h>
#include <drivers/input/keymap.h>
#include <drivers/i8042.h>
#include <drivers/diag.h>

int key_is_pressed(struct input_event *event) {
	return event->type & KEY_PRESSED;
}
#if 0
static struct input_dev *kbd;

static struct input_dev *kbd_get(void) {

	if (kbd == NULL) {
		kbd = input_dev_lookup("keyboard");

		if (kbd) {
			input_dev_open(kbd, NULL);
		}
	}
	return kbd;
}

int keyboard_getc(struct input_dev *indev) {

	static unsigned char ascii_buff[4];
	static int ascii_len;
	static int seq_cnt = 0;
	struct input_event event;

	if(ascii_len > seq_cnt) {
		return ascii_buff[seq_cnt++];
	}
	ascii_len = 0;

	do {
		while (0 != input_dev_event(kbd_get(), &event)) {

		}

		if(key_is_pressed(&event)) {
			ascii_len = keymap_to_ascii(&event, ascii_buff);
		}

	} while(ascii_len == 0);

	seq_cnt = 0;

	return ascii_buff[seq_cnt++];
}

char diag_getc(void) {
	return keyboard_getc();
}

int diag_kbhit(void) {
	return keyboard_havechar();
}
#endif
