# fix permissions on anything already there
for file in $1/*
do
    chmod +rwx "$file" 
done

# Copy required dylibs
cp "${OGRE_SDK}/lib/macosx/Release/Ogre.framework/Ogre" ./bin_release
cp "${OGRE_SDK}/lib/macosx/Release/RenderSystem_GL.framework/Versions/1.9.0/RenderSystem_GL" ./bin_release/
cp "${OGRE_SDK}/lib/macosx/Release/OgreOverlay.framework/Versions/1.9.0/OgreOverlay" ./bin_release/
cp /usr/local/lib/libboost_thread-mt.dylib ./bin_release/
cp /usr/local/lib/libboost_date_time-mt.dylib ./bin_release/
cp /usr/local/lib/libboost_system-mt.dylib ./bin_release/
cp /usr/local/lib/libboost_atomic-mt.dylib ./bin_release/
cp /usr/local/lib/libboost_chrono-mt.dylib ./bin_release/
cp /usr/local/lib/libboost_program_options-mt.dylib ./bin_release/
cp /usr/local/lib/libboost_filesystem-mt.dylib ./bin_release/
cp /usr/local/lib/libboost_unit_test_framework-mt.dylib ./bin_release/
cp /usr/local/lib/QtCore.framework/Versions/4/QtCore ./bin_release/
cp /usr/local/lib/QtGui.framework/Versions/4/QtGui ./bin_release/

# fix permissions on anything we just copied
for file in $1/*
do
    chmod +rwx "$file" 
done

# Update dylib paths in all binaries
for file in $1/*
do
   install_name_tool "$file" -change @executable_path/../Frameworks/Ogre.framework/Versions/1.9.0/Ogre @executable_path/Ogre
   install_name_tool "$file" -change @executable_path/../Frameworks/OgreOverlay.framework/Versions/1.9.0/OgreOverlay @executable_path/OgreOverlay
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_thread-mt.dylib @executable_path/libboost_thread-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_date_time-mt.dylib @executable_path/libboost_date_time-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_system-mt.dylib @executable_path/libboost_system-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_atomic-mt.dylib @executable_path/libboost_atomic-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_chrono-mt.dylib @executable_path/libboost_chrono-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_program_options-mt.dylib @executable_path/libboost_program_options-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_filesystem-mt.dylib @executable_path/libboost_filesystem-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_unit_test_framework-mt.dylib @executable_path/libboost_unit_test_framework-mt.dylib
   install_name_tool "$file" -change @@HOMEBREW_PREFIX@@/lib/libboost_chrono-mt.dylib @executable_path/libboost_chrono-mt.dylib
   
   install_name_tool "$file" -change /usr/local/lib/libboost_thread-mt.dylib @executable_path/libboost_thread-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_date_time-mt.dylib @executable_path/libboost_date_time-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_system-mt.dylib @executable_path/libboost_system-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_atomic-mt.dylib @executable_path/libboost_atomic-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_chrono-mt.dylib @executable_path/libboost_chrono-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_program_options-mt.dylib @executable_path/libboost_program_options-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_filesystem-mt.dylib @executable_path/libboost_filesystem-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_unit_test_framework-mt.dylib @executable_path/libboost_unit_test_framework-mt.dylib
   install_name_tool "$file" -change /usr/local/lib/libboost_chrono-mt.dylib @executable_path/libboost_chrono-mt.dylib
   
   
   install_name_tool "$file" -change ${PWD}/bin_release/liblua.dylib  @executable_path/liblua.dylib
   install_name_tool "$file" -change /usr/local/lib/QtCore.framework/Versions/4/QtCore @executable_path/QtCore
   install_name_tool "$file" -change /usr/local/lib/QtGui.framework/Versions/4/QtGui @executable_path/QtGui
   otool "$file" -L
done
