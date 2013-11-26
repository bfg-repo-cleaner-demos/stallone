
import os, _pystallone

__dir__ = os.path.abspath(os.path.dirname(__file__))

class JavaError(Exception):
  def getJavaException(self):
    return self.args[0]
  def __str__(self):
    writer = StringWriter()
    self.getJavaException().printStackTrace(PrintWriter(writer))
    return "\n".join((super(JavaError, self).__str__(), "    Java stacktrace:", str(writer)))

class InvalidArgsError(Exception):
  pass

_pystallone._set_exception_types(JavaError, InvalidArgsError)

VERSION = "1.0"
CLASSPATH = [os.path.join(__dir__, "stallone-1.0-SNAPSHOT-api.jar"), os.path.join(__dir__, "arpack_combined_all-0.1.jar"), os.path.join(__dir__, "colt-1.0.3.jar"), os.path.join(__dir__, "jep-2.4.1.jar"), os.path.join(__dir__, "mtj-0.9.14.jar"), os.path.join(__dir__, "netlib-java-0.9.3.jar"), os.path.join(__dir__, "stallone-1.0-SNAPSHOT-impl.jar")]
CLASSPATH = os.pathsep.join(CLASSPATH)
_pystallone.CLASSPATH = CLASSPATH
_pystallone._set_function_self(_pystallone.initVM, _pystallone)

from _pystallone import *
