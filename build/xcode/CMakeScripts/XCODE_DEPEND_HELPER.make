# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.luatest.Debug:
/Users/antondev/Learn/luatest/build/xcode/bin/luatest:
	/bin/rm -f /Users/antondev/Learn/luatest/build/xcode/bin/luatest


PostBuild.luatest.Release:
/Users/antondev/Learn/luatest/build/xcode/bin/luatest:
	/bin/rm -f /Users/antondev/Learn/luatest/build/xcode/bin/luatest


PostBuild.luatest.MinSizeRel:
/Users/antondev/Learn/luatest/build/xcode/MinSizeRel/luatest:
	/bin/rm -f /Users/antondev/Learn/luatest/build/xcode/MinSizeRel/luatest


PostBuild.luatest.RelWithDebInfo:
/Users/antondev/Learn/luatest/build/xcode/RelWithDebInfo/luatest:
	/bin/rm -f /Users/antondev/Learn/luatest/build/xcode/RelWithDebInfo/luatest




# For each target create a dummy ruleso the target does not have to exist
