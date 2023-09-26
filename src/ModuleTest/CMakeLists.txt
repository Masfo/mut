 							   
set(MODULENAME ModuleTest)

add_library(${MODULENAME})
set_property(TARGET ${MODULENAME} PROPERTY CXX_STANDARD          23)
set_property(TARGET ${MODULENAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${MODULENAME} PROPERTY CXX_EXTENSIONS        OFF)


target_sources(${MODULENAME} PUBLIC
               FILE_SET modules 
               TYPE CXX_MODULES 
               FILES 

               module.ixx
               module2.ixx
)

