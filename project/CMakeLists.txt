#Lifka --
cmake_minimum_required(VERSION 3.7)
project(project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Model/Piece.cpp Model/Piece.h Model/PieceType.h
        Model/Rotation.h Model/Point2D.cpp Model/Point2D.h Model/FactoryMethod.h Model/Factory.cpp Model/Factory.h Model/Board.cpp Model/Board.h Model/Options.cpp Model/Options.h Controller/Observer.h Controller/Subject.h Controller/Subject.cpp Controller/GameManager.cpp Controller/GameManager.h Controller/PlayerController.cpp Controller/PlayerController.h View/Drawer.cpp View/Drawer.h Model/NotifyCode.h View/BlockDrawer.cpp View/BlockDrawer.h Model/Direction.h Model/ColorPalette.cpp Model/ColorPalette.h Model/ColorName.h Model/Strings.cpp Model/Strings.h Model/PlayerInput.cpp Model/PlayerInput.h Model/keycode.h)

SET(ALLEGRO_ROOT allegro/)

INCLUDE_DIRECTORIES( ${ALLEGRO_ROOT}/include)
LINK_DIRECTORIES( /${ALLEGRO_ROOT}/lib )

add_executable(project ${SOURCE_FILES})

TARGET_INCLUDE_DIRECTORIES(project PUBLIC ${ALLEGRO_ROOT})
TARGET_LINK_LIBRARIES(project allegro
        allegro_color
        allegro_main
        allegro_primitives
        allegro_ttf
        allegro_acodec
        allegro_audio
        allegro_font)