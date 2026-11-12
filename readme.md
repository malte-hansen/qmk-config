# Corne QMK Firmware

[![Build Status](https://github.com/malte-hansen/qmk-config/actions/workflows/firmware.yml/badge.svg?branch=main)](https://github.com/malte-hansen/qmk-config/actions/workflows/firmware.yml)

This QMK fork contains the [`malte_hansen` keymap](keyboards/mechboards/crkbd/pro/keymaps/malte_hansen/) for the [Mechboards CRKBD Pro](keyboards/mechboards/crkbd/pro/), a 42-key split Corne. The QMK target is `mechboards/crkbd/pro`. The keymap selects the `sparkfun_pm2040` converter for the RP2040 controllers.

## Layout

The default macOS layer uses Colemak-DH letter positions. Holding a home-row mod-tap key activates Control, Option, Command, or Shift. Holding the rightmost thumb key sends Hyper (Control, Option, Shift, and Command). Tapping it sends Delete.

| Hold this key | Layer | Main bindings |
| --- | --- | --- |
| Escape | Window shortcuts | Hyper-modified window management on Mac |
| Backspace | Numbers | Right-hand number pad and left-hand navigation |
| Tab | Functions | F1–F15, media, volume, and brightness |
| Enter | Navigation | Right-hand arrows, Home, End, Page Up, and Page Down |
| Space | Symbols | Punctuation, brackets, and operators |

## Build

Install the QMK CLI and ARM toolchain using the [QMK setup guide](https://docs.qmk.fm/newbs_getting_started). From this checkout, initialize the submodules and compile the keymap.

```sh
git submodule update --init --recursive
qmk compile -kb mechboards/crkbd/pro -km malte_hansen
```

The build writes `mechboards_crkbd_pro_malte_hansen.uf2` to the repository root.

The [Build Corne Pro firmware workflow](https://github.com/malte-hansen/qmk-config/actions/workflows/firmware.yml) runs on pushes to `main`, pull requests targeting `main`, and manual dispatches. Open a successful run and download the `mechboards_crkbd_pro_malte_hansen` artifact to get the same UF2.

## Flash both halves

1. Unplug USB and disconnect the TRRS cable.
2. Connect one half over USB and double-tap the reset button below its TRRS jack. You can also hold the controller’s BOOTSEL button while plugging in USB.
3. Copy `mechboards_crkbd_pro_malte_hansen.uf2` to the `RPI-RP2` drive. The controller reboots and the drive disappears.
4. Repeat with the same UF2 on the other half. With USB unplugged, reconnect the TRRS cable, then plug USB into the left half.
