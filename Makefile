# Project: FlyOverBoxes

#--- Sources files -------------------------------------------------------------
FILES=Sources/Drawing/Drawing.c \
      Sources/Game/Game.c \
      Sources/Menu/Menu.c \
      Sources/Objects/Bomb.c \
      Sources/Objects/Histogram.c \
      Sources/Objects/Image.c \
      Sources/Objects/Plane.c \
      Sources/Scores/Scores.c \
      Sources/Utils/CommandParsing.c \
      Sources/Utils/Log.c \
      Sources/Utils/Options.c \
      Main.c

#--- Executable name -----------------------------------------------------------
EXECUTABLE=FlyOverBoxe

#--- Building ------------------------------------------------------------------
$(EXECUTABLE):$(FILES)
	gcc $^ -o $@

#--- Cleaning ------------------------------------------------------------------
clean:
	rm -f $(EXECUTABLE)

#--- Building and cleaning -----------------------------------------------------
all: clean $(EXECUTABLE)
