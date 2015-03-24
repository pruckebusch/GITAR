TARGET=z1

COMPILE_DYNAMIC=1
WITH_RIME=1

NETSTACK_CONF_NETWORK=rime_driver
CONF_SET_NODE_ID = 1
MOTE = 1

#~ SMALL = 1

CFLAGS += -DNETSTACK_CONF_NETWORK=rime_driver
CFLAGS += -DWITH_RIME=1
CFLAGS += -DCONF_SET_NODE_ID=1
CFLAGS += -DCOMPILE_DYNAMIC=1

PROJECTDIRS += /home/user/Documents/Software/CLEAN_COPY/GITAR/src/dynamic/net/rime/
PROJECTDIRS += /home/user/Documents/Software/CLEAN_COPY/GITAR/src/dynamic/examples/rime/
PROJECT_SOURCEFILES += example-mesh.c
#example-collect.c example-announcement.c example-multihop.c example-polite.c example-rudolph0.c example-rudolph2.c example-trickle.c example-abc.c example-neighbors.c example-rucb.c example-rudolph1.c example-runicast.c example-unicast.c
#~ broadcast.c collect-link-estimate.c ipolite.c multihop.c neighbor-discovery.c polite-announcement.c route.c rucb.c rudolph1.c runicast.c stunicast.c trickle.c collect.c collect-neighbor.c mesh.c nbr-table.c netflood.c polite.c rmh.c route-discovery.c rudolph0.c rudolph2.c stbroadcast.c timesynch.c unicast.c

GITAR_PROJECT = example-collect
#~ all: broadcast collect-link-estimate ipolite multihop neighbor-discovery polite-announcement route rucb rudolph1 runicast stunicast trickle collect collect-neighbor mesh nbr-table netflood polite rmh route-discovery rudolph0 rudolph2 stbroadcast timesynch unicast

#~ example-broadcast.ce: broadcast.ce example-broadcast.c

GITAR = /home/user/Documents/Software/CLEAN_COPY/GITAR
include $(GITAR)/make/Makefile.gitar
