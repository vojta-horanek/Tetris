ADD_DEFINITIONS(-DTESTDATA_DIR="${PROJECT_SOURCE_DIR}/testdata")

SET(EXAMPLES
        audio_sine
        audio_wav
        lines
        rendertarget
        sprites
        )

IF (SDL2PP_WITH_IMAGE)
    SET(EXAMPLES ${EXAMPLES}
            image
            fill
            )
ENDIF (SDL2PP_WITH_IMAGE)

IF (SDL2PP_WITH_MIXER)
    SET(EXAMPLES ${EXAMPLES}
            mixer
            mixer_music
            mixer_music_sine
            mixer_effects
            )
ENDIF (SDL2PP_WITH_MIXER)

IF (SDL2PP_WITH_TTF)
    SET(EXAMPLES ${EXAMPLES}
            ttf
            )
ENDIF (SDL2PP_WITH_TTF)

FOREACH (EXAMPLE ${EXAMPLES})
    ADD_EXECUTABLE(${EXAMPLE} ${EXAMPLE}.cc)
    TARGET_LINK_LIBRARIES(${EXAMPLE} ${SDL2PP_LIBRARIES})
ENDFOREACH (EXAMPLE)
