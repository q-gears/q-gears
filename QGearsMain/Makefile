####################################################################
#                                                                  #
#		Q-Gears		                                                 #
#                                                                  #
#		Depends 	: OGRE, OIS, openal, vorbisfile                     #
#		Internal : lua, luabind, tinyxml										 #
#                                                                  #
#		make DEBUG=1 - Debug                                         #
#		make			 - Release													 #
#                 		                                           #
####################################################################

# Useful stuff, for eg. cross-compiling
INCLUDE_DIR  := /usr/include
OGRE_INCLUDE := ${INCLUDE_DIR}/OGRE
OIS_INCLUDE  := ${INCLUDE_DIR}/OIS
CFLAGS		 := `pkg-config OGRE OIS openal vorbisfile --cflags`
CXXFLAGS		 := `pkg-config OGRE OIS openal vorbisfile --cflags`
LIBS			 := `pkg-config OGRE OIS openal vorbisfile --libs`
DEBUG			 := 0

# ---- Q-GEARS Specific ----
CORE_DIR 	 := core
VIEWER_DIR   := viewer
QGEARS_BIN	 := QGears
BUILD_DIR	 := ../output

# ATM there is no intelligent render system selection,
# so put your rendersystem path here and it gets copied to build dir
# with name "RenderSystem_GL.so" or "RenderSystem_GL_d.so" in debug mode
OGRE_RENDERER			:= /usr/lib/OGRE/RenderSystem_GL.so

# ---- Libs that come with Q-Gears ---
INTERNAL_LIB_DIR 		:= ${CORE_DIR}/library
LUA_DIR 					:= ${INTERNAL_LIB_DIR}/lua
LUABIND_DIR 			:= ${INTERNAL_LIB_DIR}/luabind
TINYXML_DIR 			:= ${INTERNAL_LIB_DIR}/tinyxml

# If you set these to 0, we will try to use system libs instead
BUILD_INTERNAL_LUA		:= 1
BUILD_INTERNAL_LUABIND 	:= 1
BUILD_INTERNAL_TINYXML	:= 1

# Define libs for these if you don't want to build them
# Default values are just a guess, there is no quarntee all of them come with pkg-configs
LUA_LIB 		= `pkg-config lua --libs`
LUABIND_LIB = `pkg-config luabind --libs`
TINYXML_LIB	= `pkg-config tinyxml --libs`

# ---- A.I ----
# Intenal libs should be build before anything else.
ifeq (${BUILD_INTERNAL_LUA},1)
	SOURCE += $(patsubst %.c,%,$(wildcard ${LUA_DIR}/*.c))
else
	LIBS 	 	+= ${LUA_LIB}
	INCLUDES	+= -I${LUA_DIR}
endif

ifeq (${BUILD_INTERNAL_LUABIND},1)
	SOURCE += $(patsubst %.cpp,%,$(wildcard ${LUABIND_DIR}/*.cpp))
else
	LIBS   	+= ${LUABIND_LIB}
	INCLUDES += -I${LUABIND_DIR}
endif

ifeq (${BUILD_INTERNAL_TINYXML},1)
	SOURCE += $(patsubst %.cpp,%,$(wildcard ${TINYXML_DIR}/*.cpp))
else
	LIBS   	+= ${TINYXML_LIB}
	INCLUDES += -I${TINYXML_DIR}
endif

ifeq (${DEBUG},1)
	DEFINES += -D_DEBUG
	CFLAGS   = -g -O0
	CXXFLAGS = -g -O0
endif

# ---- Build defines ----
SOURCE	  += 	Main.cpp																			\
					$(patsubst %.cpp,%,$(wildcard core/*.cpp))    						\
            	$(patsubst %.cpp,%,$(wildcard core/particles/*.cpp)) 				\
					$(patsubst %.cpp,%,$(wildcard core/particles/emitters/*.cpp)) 	\
					$(patsubst %.cpp,%,$(wildcard core/particles/renderer/*.cpp))
DEFINES	  += -DTIXML_USE_STL
INCLUDES	  += -I. -I${VIEWER_DIR} -I${CORE_DIR} -I${INCLUDE_DIR} -I${OGRE_INCLUDE} -I${OIS_INCLUDE} -I${INTERNAL_LIB_DIR}
TARGET		= ${BUILD_DIR}/${QGEARS_BIN}
OBJ			= $(addsuffix .o, $(basename $(SOURCE)))

all: ${TARGET}
	@true

# Ugly CPP
%.o : %.cpp
	${CXX} ${CXXFLAGS} ${DEFINES} ${INCLUDES} -c $^ -o $@

# Good old C
%.o : %.c
	${CC} ${CFLAGS} ${DEFINES} ${INCLUDES} -c $^ -o $@

# Link, create build dir if does not exist
${TARGET}: ${OBJ}
	mkdir -p "${BUILD_DIR}"
	${CXX} $^ ${LIBS} -o "${TARGET}"

ifeq (${DEBUG},1)
		cp "${OGRE_RENDERER}" "${BUILD_DIR}/RenderSystem_GL_d.so"
else
		cp "${OGRE_RENDERER}" "${BUILD_DIR}/RenderSystem_GL.so"
endif

# Note: Don't clean ${BUILD_DIR} it's generally non good idea for deveploment
clean:
	${RM}  ${OBJ}
	${RM}  "${TARGET}"

# TO-DO
# Note: Use ${PREFIX} for install location
install:
	echo "Not yet implented"
