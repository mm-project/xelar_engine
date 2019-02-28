# xelar engine

#### background 
This is fun project originated from attempts to generalize some infratcure code after long struggling with some silly game that has been on my shelf long time ago. I've come up with idea to build sort of "engine" that will act as an intemediate layer instead of binding game to certain engine/framework ( sdl, qt..)

What that means is that each concrete component (rendering, sound engine, networking,etc..) can be connnected to any of existing framework/libararies by inheriting base interfaces and implementing the stuff. The advantage of such system is that there will be no code change ( ideally ) on client code when tranfering game to one framework/platform to another.

Sounds extrimelly ambitious, but this still going project and we'll see how far we can get :)

By default rendering back-end is bound to sdl. This allows us to port to android any of games created by xelar_engine. Qt rendering/controller backend support is on the way.

#### Some screenshots from games compiled:
Dzuk-Dzukik ( ported to Android )
<img src="https://i.ibb.co/WP6y8jY/52146452-1228258580646639-1617230026472685568-n.png">

Labyrynt ( ported to Android )
<img src="https://i.ibb.co/DWCr2mt/51604126-1218603821621061-8738384312610586624-n.png">

