proton 
======

proton is a terminal-based chat client for Linux and macOS with support for
Telegram.

Features 
--------
- Message history cache (sqlite db backed)
- View/save media files: documents, phots
- Show user status (online, away, typing)
- Message read receipt
- List dialogs (with text filter) for selecting files, emojis, contacts
- Reply / delete / send messages
- Jump to unread chat
- Toggle to view textized emojis vs graphical (default)
- Toggle to hide/show UI elements (top bar, status bar, help bar, contact list)
- Receive / send markdown formatted messages
- Customizable color schemes and key bindings

Usage
=====
Usage:

    proton [OPTION]

Command-line Options:
    
    -d, --confdir <DIR>   use a different directory than ~/.proton
    -e, --verbose         enable verbose logging
    -ee, --extra-verbose  enable extra verbose logging
    -h, --help            display the help and exit
    -s, --setup           set up chat protocol account
    -v, --version         output version information and exit
    -x, --export <DIR>    export messages cache to specified dir

Interactive Commands:

    PageDn                history next page
    PageUp                history previous page
    Tab                   next chat
    Sh-Tab                previous chat
    Ctrl-e                insert emoji
    Ctrl-g                toggle show help bar
    Ctrl-l                toggle show contact list
    Ctrl-p                toggle show top bar
    Ctrl-q                quit
    Ctrl-s                search contacts
    Ctrl-t                send file
    Ctrl-u                jump to unread chat
    Ctrl-x                send messages
    Ctrl-y                toggle show emojis
    KeyUp                 select messages

Interactive Commands for Selected Message:

    Ctrl-d                delete selected message
    Ctrl-r                download attached file
    Ctrl-v                open/view attached file
    Ctrl-x                reply to selected message

Build / Install
===============

proton consists of a large code-base (mainly the Telegram client library), so be
prepared for a relatively long first build time. Subsequent builds will be
faster.

Linux / Ubuntu
--------------

**Dependencies**

    sudo apt install ccache cmake build-essential gperf help2man libreadline-dev libssl-dev libncurses-dev libncursesw5-dev ncurses-doc zlib1g-dev libsqlite3-dev libmagic-dev

**Source**

    git clone https://github.com/x0x/proton && cd proton

**Build**

    mkdir -p build && cd build && cmake .. && make -sudo

**Install**
    
    sudo make install

macOS
-----
**Dependencies**

    brew install gperf cmake openssl ncurses ccache readline help2man sqlite libmagic

**Source**

    git clone https://github.com/x0x/proton && cd proton

**Build**

    mkdir -p build && cd build && cmake .. && make -s

**Install**

    make install

Low Memory / RAM Systems
------------------------
The Telegram client library subcomponent requires relatively large amount of RAM to
build by default (3.5GB using g++, and 1.5 GB for clang++). It is possible to adjust the
Telegram client library source code so that it requires less RAM (but takes longer time).
Doing so reduces the memory requirement to around 1GB under g++ and 0.5GB for clang++. Also, it
is recommended to build proton in release mode (which is default if downloading zip/tar release
package - but with a git/svn clone it defaults to debug mode), to minimize memory usage.
Steps to build proton on a low memory system:

**Source**

    git clone https://github.com/x0x/proton && cd proton

**Build**

    cd lib/tgchat/ext/td ; php SplitSource.php ; cd -
    mkdir -p build && cd build
    CC=/usr/bin/clang CXX=/usr/bin/clang++ cmake -DCMAKE_BUILD_TYPE=Release .. && make -s

**Install**

    sudo make install

**Revert Source Code Split (Optional)**

    cd ../lib/tgchat/ext/td ; php SplitSource.php --undo ; cd -   # optional step to revert source split

Getting Started
===============
In order to configure / setup an account one needs to run proton in setup mode:
    
    proton --setup
    
The setup mode prompts for phone number, which shall be enterted with country
code. Example:

    $ proton --setup
    Protocols:
    0.Telegram
    1.Exit setup
    Select protocol (1): 0
    Enter phone number (ex. +6511111111): +6511111111
    Enter authentication code: xxxxx
    Succesfully set up profile Telegram_+6511111111

Once the setup process is completed proton will exit, and can now be restarted
in normal mode:

    proton 

Security
========
User data is stored locally in `~/.proton`. Default file permissions
only allow user access, but anyone who can gain access to a user's private
files can also access the user's personal Telegram data. To protect against
the most simple attack vectors it may be suitable to use disk encryption and
to ensure `~/.proton` is not backed up unencrypted.


Configuration
=============
The following configuration files (listed with current default values) can be
used to configure proton.

~/.proton/app.conf
-----------------
This configuration file holds general application settings. Default content:

    cache_enabled=1

~/.proton/ui.conf
----------------
This configuration file holds general user interface settings. Default content:

    confirm_deletion=1
    emoji_enabled=1
    help_enabled=1
    home_fetch_all=0
    list_enabled=1
    top_enabled=1

~/.proton/key.conf
-----------------
This configuration file holds user interface key bindings. Default content:

    backspace=KEY_BACKSPACE
    cancel=KEY_CTRLC
    delete=KEY_DC
    delete_msg=KEY_CTRLD
    down=KEY_DOWN
    end=KEY_END
    home=KEY_HOME
    left=KEY_LEFT
    next_chat=KEY_TAB
    next_page=KEY_NPAGE
    open=KEY_CTRLV
    other_commands_help=KEY_CTRLO
    prev_chat=KEY_BTAB
    prev_page=KEY_PPAGE
    quit=KEY_CTRLQ
    return=KEY_RETURN
    right=KEY_RIGHT
    save=KEY_CTRLR
    select_contact=KEY_CTRLS
    select_emoji=KEY_CTRLE
    send_msg=KEY_CTRLX
    toggle_emoji=KEY_CTRLY
    toggle_help=KEY_CTRLG
    toggle_list=KEY_CTRLL
    toggle_top=KEY_CTRLP
    transfer=KEY_CTRLT
    unread_chat=KEY_CTRLU
    up=KEY_UP

Refer to function UiKeyConfig::GetKeyCode() in
[uikeyconfig.cpp](https://github.com/x0x/proton/tree/main/src/uikeyconfig.cpp)
for a list of supported key names to use in the config file. Alternatively
key codes may be entered in hex format (e.g. 0x9).

~/.proton/color.conf
-------------------
This configuration file holds user interface color settings. Default content:

    dialog_attr=
    dialog_attr_selected=reverse
    dialog_color_bg=
    dialog_color_fg=
    entry_attr=
    entry_color_bg=
    entry_color_fg=
    help_attr=reverse
    help_color_bg=black
    help_color_fg=white
    history_name_attr=bold
    history_name_attr_selected=reverse
    history_name_recv_color_bg=
    history_name_recv_color_fg=
    history_name_sent_color_bg=
    history_name_sent_color_fg=gray
    history_text_attr=
    history_text_attr_selected=reverse
    history_text_recv_color_bg=
    history_text_recv_color_fg=
    history_text_sent_color_bg=
    history_text_sent_color_fg=gray
    list_attr=
    list_attr_selected=bold
    list_color_bg=
    list_color_fg=
    listborder_attr=
    listborder_color_bg=
    listborder_color_fg=
    status_attr=reverse
    status_color_bg=
    status_color_fg=
    top_attr=reverse
    top_color_bg=
    top_color_fg=

Supported text attributes `_attr` (defaults to `normal` if not specified):

    normal
    underline
    reverse
    bold
    italic

Supported text background `_bg` and foreground `_fg` colors:

    black
    red
    green
    yellow
    blue
    magenta
    cyan
    white
    gray
    bright_black (same as gray)
    bright_red
    bright_green
    bright_yellow
    bright_blue
    bright_magenta
    bright_cyan
    bright_white

Custom colors may be specified using hex RGB code, for example `0xff8937`.

General
-------
Deleting a configuration entry line (while proton is not running) and starting
proton will populate the configuration file with the default entry.


Limitations
===========
Known limitations:

- Messages deleted using other devices/clients will not be deleted in proton
  history if local cache is enabled.


Technical Details
=================

Third-party Libraries
---------------------
proton is primarily implemented in C++ with some parts in Go. Its source tree
includes the source code of the following third-party libraries:

- [apathy](https://github.com/dlecocq/apathy) -
  Copyright 2013 Dan Lecocq - [MIT License](/ext/apathy/LICENSE)

- [emojicpp](https://github.com/99x/emojicpp) -
  Copyright 2018 Shalitha Suranga - [MIT License](/ext/emojicpp/LICENSE)

- [go-qrcode](https://github.com/skip2/go-qrcode) -
  Copyright 2014 Tom Harwood -
  [MIT License](/lib/wachat/go/ext/go-qrcode/LICENSE)

- [go-whatsapp](https://github.com/Rhymen/go-whatsapp) -
  Copyright 2018 Lucas Engelke -
  [MIT License](/lib/wachat/go/ext/go-whatsapp/LICENSE)

- [sqlite_modern_cpp](https://github.com/SqliteModernCpp/sqlite_modern_cpp) -
  Copyright 2017 aminroosta - [MIT License](/ext/sqlite_modern_cpp/License.txt)

- [tdlib](https://github.com/tdlib/td) -
  Copyright 2014 Aliaksei Levin, Arseny Smirnov -
  [Boost License](/lib/tgchat/ext/td/LICENSE_1_0.txt)

Code Formatting
---------------
Uncrustify is used to maintain consistent source code formatting, example:

    ./make.sh src

License
=======
proton is distributed under the MIT license. See LICENSE file.
