TARGET=z1

WITH_RIME=1

NETSTACK_CONF_NETWORK=rime_driver
CONF_SET_NODE_ID = 1
MOTE = 1

#~ SMALL = 1

CFLAGS += -DNETSTACK_CONF_NETWORK=rime_driver
CFLAGS += -DWITH_RIME=1
CFLAGS += -DCONF_SET_NODE_ID=1

PROJECTDIRS += /home/user/Documents/Software/GITAR/src/user/apps/rime-tests-dynamic/
PROJECT_SOURCEFILES + =example-abc.c example-broadcast.c example-mesh.c example-neighbors.c example-rucb.c example-rudolph1.c example-runicast.c example-unicast.c example-announcement.c example-collect.c example-multihop.c example-polite.c example-rudolph0.c example-rudolph2.c example-trickle.c

#~ GITAR_PROJECT = example-abc
all: example-abc example-broadcast example-mesh example-neighbors example-rucb example-rudolph1 example-runicast example-unicast example-announcement example-collect example-multihop example-polite example-rudolph0 example-rudolph2 example-trickle

GITAR = /home/user/Documents/Software/CLEAN_COPY/GITAR
include $(GITAR)/make/Makefile.gitar
