#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/InstantiationException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *InstantiationException::class$ = NULL;
    jmethodID *InstantiationException::mids$ = NULL;
    bool InstantiationException::live$ = false;

    jclass InstantiationException::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/InstantiationException");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    InstantiationException::InstantiationException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    InstantiationException::InstantiationException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_InstantiationException_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_InstantiationException_instance_(PyTypeObject *type, PyObject *arg);
    static int t_InstantiationException_init_(t_InstantiationException *self, PyObject *args, PyObject *kwds);

    static PyMethodDef t_InstantiationException__methods_[] = {
      DECLARE_METHOD(t_InstantiationException, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_InstantiationException, instance_, METH_O | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(InstantiationException, t_InstantiationException, ::java::lang::Exception, InstantiationException, t_InstantiationException_init_, 0, 0, 0, 0, 0);

    void t_InstantiationException::install(PyObject *module)
    {
      installType(&PY_TYPE(InstantiationException), module, "InstantiationException", 0);
    }

    void t_InstantiationException::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(InstantiationException).tp_dict, "class_", make_descriptor(InstantiationException::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(InstantiationException).tp_dict, "wrapfn_", make_descriptor(t_InstantiationException::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(InstantiationException).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_InstantiationException_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, InstantiationException::initializeClass, 1)))
        return NULL;
      return t_InstantiationException::wrap_Object(InstantiationException(((t_InstantiationException *) arg)->object.this$));
    }
    static PyObject *t_InstantiationException_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, InstantiationException::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_InstantiationException_init_(t_InstantiationException *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          InstantiationException object((jobject) NULL);

          INT_CALL(object = InstantiationException());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          InstantiationException object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = InstantiationException(a0));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/SecurityException.h"
#include "java/lang/Throwable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *SecurityException::class$ = NULL;
    jmethodID *SecurityException::mids$ = NULL;
    bool SecurityException::live$ = false;

    jclass SecurityException::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/SecurityException");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_init$_c5ec8ca4] = env->getMethodID(cls, "<init>", "(Ljava/lang/Throwable;)V");
        mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    SecurityException::SecurityException() : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    SecurityException::SecurityException(const ::java::lang::String & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    SecurityException::SecurityException(const ::java::lang::Throwable & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_c5ec8ca4, a0.this$)) {}

    SecurityException::SecurityException(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_SecurityException_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_SecurityException_instance_(PyTypeObject *type, PyObject *arg);
    static int t_SecurityException_init_(t_SecurityException *self, PyObject *args, PyObject *kwds);

    static PyMethodDef t_SecurityException__methods_[] = {
      DECLARE_METHOD(t_SecurityException, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_SecurityException, instance_, METH_O | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(SecurityException, t_SecurityException, ::java::lang::RuntimeException, SecurityException, t_SecurityException_init_, 0, 0, 0, 0, 0);

    void t_SecurityException::install(PyObject *module)
    {
      installType(&PY_TYPE(SecurityException), module, "SecurityException", 0);
    }

    void t_SecurityException::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(SecurityException).tp_dict, "class_", make_descriptor(SecurityException::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(SecurityException).tp_dict, "wrapfn_", make_descriptor(t_SecurityException::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(SecurityException).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_SecurityException_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, SecurityException::initializeClass, 1)))
        return NULL;
      return t_SecurityException::wrap_Object(SecurityException(((t_SecurityException *) arg)->object.this$));
    }
    static PyObject *t_SecurityException_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, SecurityException::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_SecurityException_init_(t_SecurityException *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          SecurityException object((jobject) NULL);

          INT_CALL(object = SecurityException());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          SecurityException object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = SecurityException(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::Throwable a0((jobject) NULL);
          SecurityException object((jobject) NULL);

          if (!parseArgs(args, "k", ::java::lang::Throwable::initializeClass, &a0))
          {
            INT_CALL(object = SecurityException(a0));
            self->object = object;
            break;
          }
        }
        goto err;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          ::java::lang::Throwable a1((jobject) NULL);
          SecurityException object((jobject) NULL);

          if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
          {
            INT_CALL(object = SecurityException(a0, a1));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *NumberFormatException::class$ = NULL;
    jmethodID *NumberFormatException::mids$ = NULL;
    bool NumberFormatException::live$ = false;

    jclass NumberFormatException::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/NumberFormatException");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    NumberFormatException::NumberFormatException() : ::java::lang::IllegalArgumentException(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    NumberFormatException::NumberFormatException(const ::java::lang::String & a0) : ::java::lang::IllegalArgumentException(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_NumberFormatException_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_NumberFormatException_instance_(PyTypeObject *type, PyObject *arg);
    static int t_NumberFormatException_init_(t_NumberFormatException *self, PyObject *args, PyObject *kwds);

    static PyMethodDef t_NumberFormatException__methods_[] = {
      DECLARE_METHOD(t_NumberFormatException, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_NumberFormatException, instance_, METH_O | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(NumberFormatException, t_NumberFormatException, ::java::lang::IllegalArgumentException, NumberFormatException, t_NumberFormatException_init_, 0, 0, 0, 0, 0);

    void t_NumberFormatException::install(PyObject *module)
    {
      installType(&PY_TYPE(NumberFormatException), module, "NumberFormatException", 0);
    }

    void t_NumberFormatException::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(NumberFormatException).tp_dict, "class_", make_descriptor(NumberFormatException::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(NumberFormatException).tp_dict, "wrapfn_", make_descriptor(t_NumberFormatException::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(NumberFormatException).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_NumberFormatException_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, NumberFormatException::initializeClass, 1)))
        return NULL;
      return t_NumberFormatException::wrap_Object(NumberFormatException(((t_NumberFormatException *) arg)->object.this$));
    }
    static PyObject *t_NumberFormatException_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, NumberFormatException::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_NumberFormatException_init_(t_NumberFormatException *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          NumberFormatException object((jobject) NULL);

          INT_CALL(object = NumberFormatException());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          NumberFormatException object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = NumberFormatException(a0));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/lang/Throwable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *ClassNotFoundException::class$ = NULL;
    jmethodID *ClassNotFoundException::mids$ = NULL;
    bool ClassNotFoundException::live$ = false;

    jclass ClassNotFoundException::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/ClassNotFoundException");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");
        mids$[mid_getCause_9a29189d] = env->getMethodID(cls, "getCause", "()Ljava/lang/Throwable;");
        mids$[mid_getException_9a29189d] = env->getMethodID(cls, "getException", "()Ljava/lang/Throwable;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    ClassNotFoundException::ClassNotFoundException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    ClassNotFoundException::ClassNotFoundException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    ClassNotFoundException::ClassNotFoundException(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}

    ::java::lang::Throwable ClassNotFoundException::getCause() const
    {
      return ::java::lang::Throwable(env->callObjectMethod(this$, mids$[mid_getCause_9a29189d]));
    }

    ::java::lang::Throwable ClassNotFoundException::getException() const
    {
      return ::java::lang::Throwable(env->callObjectMethod(this$, mids$[mid_getException_9a29189d]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_ClassNotFoundException_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_ClassNotFoundException_instance_(PyTypeObject *type, PyObject *arg);
    static int t_ClassNotFoundException_init_(t_ClassNotFoundException *self, PyObject *args, PyObject *kwds);
    static PyObject *t_ClassNotFoundException_getCause(t_ClassNotFoundException *self, PyObject *args);
    static PyObject *t_ClassNotFoundException_getException(t_ClassNotFoundException *self);
    static PyObject *t_ClassNotFoundException_get__cause(t_ClassNotFoundException *self, void *data);
    static PyObject *t_ClassNotFoundException_get__exception(t_ClassNotFoundException *self, void *data);
    static PyGetSetDef t_ClassNotFoundException__fields_[] = {
      DECLARE_GET_FIELD(t_ClassNotFoundException, cause),
      DECLARE_GET_FIELD(t_ClassNotFoundException, exception),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_ClassNotFoundException__methods_[] = {
      DECLARE_METHOD(t_ClassNotFoundException, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_ClassNotFoundException, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_ClassNotFoundException, getCause, METH_VARARGS),
      DECLARE_METHOD(t_ClassNotFoundException, getException, METH_NOARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(ClassNotFoundException, t_ClassNotFoundException, ::java::lang::Exception, ClassNotFoundException, t_ClassNotFoundException_init_, 0, 0, t_ClassNotFoundException__fields_, 0, 0);

    void t_ClassNotFoundException::install(PyObject *module)
    {
      installType(&PY_TYPE(ClassNotFoundException), module, "ClassNotFoundException", 0);
    }

    void t_ClassNotFoundException::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(ClassNotFoundException).tp_dict, "class_", make_descriptor(ClassNotFoundException::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(ClassNotFoundException).tp_dict, "wrapfn_", make_descriptor(t_ClassNotFoundException::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(ClassNotFoundException).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_ClassNotFoundException_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, ClassNotFoundException::initializeClass, 1)))
        return NULL;
      return t_ClassNotFoundException::wrap_Object(ClassNotFoundException(((t_ClassNotFoundException *) arg)->object.this$));
    }
    static PyObject *t_ClassNotFoundException_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, ClassNotFoundException::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_ClassNotFoundException_init_(t_ClassNotFoundException *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          ClassNotFoundException object((jobject) NULL);

          INT_CALL(object = ClassNotFoundException());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          ClassNotFoundException object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = ClassNotFoundException(a0));
            self->object = object;
            break;
          }
        }
        goto err;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          ::java::lang::Throwable a1((jobject) NULL);
          ClassNotFoundException object((jobject) NULL);

          if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
          {
            INT_CALL(object = ClassNotFoundException(a0, a1));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_ClassNotFoundException_getCause(t_ClassNotFoundException *self, PyObject *args)
    {
      ::java::lang::Throwable result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.getCause());
        return ::java::lang::t_Throwable::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(ClassNotFoundException), (PyObject *) self, "getCause", args, 2);
    }

    static PyObject *t_ClassNotFoundException_getException(t_ClassNotFoundException *self)
    {
      ::java::lang::Throwable result((jobject) NULL);
      OBJ_CALL(result = self->object.getException());
      return ::java::lang::t_Throwable::wrap_Object(result);
    }

    static PyObject *t_ClassNotFoundException_get__cause(t_ClassNotFoundException *self, void *data)
    {
      ::java::lang::Throwable value((jobject) NULL);
      OBJ_CALL(value = self->object.getCause());
      return ::java::lang::t_Throwable::wrap_Object(value);
    }

    static PyObject *t_ClassNotFoundException_get__exception(t_ClassNotFoundException *self, void *data)
    {
      ::java::lang::Throwable value((jobject) NULL);
      OBJ_CALL(value = self->object.getException());
      return ::java::lang::t_Throwable::wrap_Object(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Iterable.h"
#include "java/util/Iterator.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Iterable::class$ = NULL;
    jmethodID *Iterable::mids$ = NULL;
    bool Iterable::live$ = false;

    jclass Iterable::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Iterable");

        mids$ = new jmethodID[max_mid];
        mids$[mid_iterator_40858c90] = env->getMethodID(cls, "iterator", "()Ljava/util/Iterator;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    ::java::util::Iterator Iterable::iterator() const
    {
      return ::java::util::Iterator(env->callObjectMethod(this$, mids$[mid_iterator_40858c90]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Iterable_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Iterable_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Iterable_of_(t_Iterable *self, PyObject *args);
    static PyObject *t_Iterable_iterator(t_Iterable *self);
    static PyObject *t_Iterable_get__parameters_(t_Iterable *self, void *data);
    static PyGetSetDef t_Iterable__fields_[] = {
      DECLARE_GET_FIELD(t_Iterable, parameters_),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Iterable__methods_[] = {
      DECLARE_METHOD(t_Iterable, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Iterable, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Iterable, of_, METH_VARARGS),
      DECLARE_METHOD(t_Iterable, iterator, METH_NOARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Iterable, t_Iterable, ::java::lang::Object, Iterable, abstract_init, ((PyObject *(*)(t_Iterable *)) get_generic_iterator< t_Iterable >), 0, t_Iterable__fields_, 0, 0);
    PyObject *t_Iterable::wrap_Object(const Iterable& object, PyTypeObject *T)
    {
      PyObject *obj = t_Iterable::wrap_Object(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Iterable *self = (t_Iterable *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    PyObject *t_Iterable::wrap_jobject(const jobject& object, PyTypeObject *T)
    {
      PyObject *obj = t_Iterable::wrap_jobject(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Iterable *self = (t_Iterable *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    void t_Iterable::install(PyObject *module)
    {
      installType(&PY_TYPE(Iterable), module, "Iterable", 0);
    }

    void t_Iterable::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Iterable).tp_dict, "class_", make_descriptor(Iterable::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Iterable).tp_dict, "wrapfn_", make_descriptor(t_Iterable::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Iterable).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Iterable_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Iterable::initializeClass, 1)))
        return NULL;
      return t_Iterable::wrap_Object(Iterable(((t_Iterable *) arg)->object.this$));
    }
    static PyObject *t_Iterable_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Iterable::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_Iterable_of_(t_Iterable *self, PyObject *args)
    {
      if (!parseArg(args, "T", 1, &(self->parameters)))
        Py_RETURN_SELF;
      return PyErr_SetArgsError((PyObject *) self, "of_", args);
    }

    static PyObject *t_Iterable_iterator(t_Iterable *self)
    {
      ::java::util::Iterator result((jobject) NULL);
      OBJ_CALL(result = self->object.iterator());
      return ::java::util::t_Iterator::wrap_Object(result, self->parameters[0]);
    }
    static PyObject *t_Iterable_get__parameters_(t_Iterable *self, void *data)
    {
      return typeParameters(self->parameters, sizeof(self->parameters));
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Appendable.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Appendable::class$ = NULL;
    jmethodID *Appendable::mids$ = NULL;
    bool Appendable::live$ = false;

    jclass Appendable::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Appendable");

        mids$ = new jmethodID[max_mid];
        mids$[mid_append_fac808c8] = env->getMethodID(cls, "append", "(C)Ljava/lang/Appendable;");
        mids$[mid_append_ca3c2aa4] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/Appendable;");
        mids$[mid_append_7f83fd04] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/Appendable;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    Appendable Appendable::append(jchar a0) const
    {
      return Appendable(env->callObjectMethod(this$, mids$[mid_append_fac808c8], a0));
    }

    Appendable Appendable::append(const ::java::lang::CharSequence & a0) const
    {
      return Appendable(env->callObjectMethod(this$, mids$[mid_append_ca3c2aa4], a0.this$));
    }

    Appendable Appendable::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
    {
      return Appendable(env->callObjectMethod(this$, mids$[mid_append_7f83fd04], a0.this$, a1, a2));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Appendable_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Appendable_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Appendable_append(t_Appendable *self, PyObject *args);

    static PyMethodDef t_Appendable__methods_[] = {
      DECLARE_METHOD(t_Appendable, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Appendable, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Appendable, append, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Appendable, t_Appendable, ::java::lang::Object, Appendable, abstract_init, 0, 0, 0, 0, 0);

    void t_Appendable::install(PyObject *module)
    {
      installType(&PY_TYPE(Appendable), module, "Appendable", 0);
    }

    void t_Appendable::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Appendable).tp_dict, "class_", make_descriptor(Appendable::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Appendable).tp_dict, "wrapfn_", make_descriptor(t_Appendable::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Appendable).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Appendable_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Appendable::initializeClass, 1)))
        return NULL;
      return t_Appendable::wrap_Object(Appendable(((t_Appendable *) arg)->object.this$));
    }
    static PyObject *t_Appendable_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Appendable::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_Appendable_append(t_Appendable *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jchar a0;
          Appendable result((jobject) NULL);

          if (!parseArgs(args, "C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_Appendable::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          Appendable result((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_Appendable::wrap_Object(result);
          }
        }
        break;
       case 3:
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          jint a1;
          jint a2;
          Appendable result((jobject) NULL);

          if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_Appendable::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "append", args);
      return NULL;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/StackTraceElement.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *StackTraceElement::class$ = NULL;
    jmethodID *StackTraceElement::mids$ = NULL;
    bool StackTraceElement::live$ = false;

    jclass StackTraceElement::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/StackTraceElement");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_fa754eea] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
        mids$[mid_equals_290588e2] = env->getMethodID(cls, "equals", "(Ljava/lang/Object;)Z");
        mids$[mid_getClassName_14c7b5c5] = env->getMethodID(cls, "getClassName", "()Ljava/lang/String;");
        mids$[mid_getFileName_14c7b5c5] = env->getMethodID(cls, "getFileName", "()Ljava/lang/String;");
        mids$[mid_getLineNumber_54c6a179] = env->getMethodID(cls, "getLineNumber", "()I");
        mids$[mid_getMethodName_14c7b5c5] = env->getMethodID(cls, "getMethodName", "()Ljava/lang/String;");
        mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
        mids$[mid_isNativeMethod_54c6a16a] = env->getMethodID(cls, "isNativeMethod", "()Z");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    StackTraceElement::StackTraceElement(const ::java::lang::String & a0, const ::java::lang::String & a1, const ::java::lang::String & a2, jint a3) : ::java::lang::Object(env->newObject(initializeClass, &mids$, mid_init$_fa754eea, a0.this$, a1.this$, a2.this$, a3)) {}

    jboolean StackTraceElement::equals(const ::java::lang::Object & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_equals_290588e2], a0.this$);
    }

    ::java::lang::String StackTraceElement::getClassName() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getClassName_14c7b5c5]));
    }

    ::java::lang::String StackTraceElement::getFileName() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getFileName_14c7b5c5]));
    }

    jint StackTraceElement::getLineNumber() const
    {
      return env->callIntMethod(this$, mids$[mid_getLineNumber_54c6a179]);
    }

    ::java::lang::String StackTraceElement::getMethodName() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getMethodName_14c7b5c5]));
    }

    jint StackTraceElement::hashCode() const
    {
      return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
    }

    jboolean StackTraceElement::isNativeMethod() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isNativeMethod_54c6a16a]);
    }

    ::java::lang::String StackTraceElement::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_StackTraceElement_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_StackTraceElement_instance_(PyTypeObject *type, PyObject *arg);
    static int t_StackTraceElement_init_(t_StackTraceElement *self, PyObject *args, PyObject *kwds);
    static PyObject *t_StackTraceElement_equals(t_StackTraceElement *self, PyObject *args);
    static PyObject *t_StackTraceElement_getClassName(t_StackTraceElement *self);
    static PyObject *t_StackTraceElement_getFileName(t_StackTraceElement *self);
    static PyObject *t_StackTraceElement_getLineNumber(t_StackTraceElement *self);
    static PyObject *t_StackTraceElement_getMethodName(t_StackTraceElement *self);
    static PyObject *t_StackTraceElement_hashCode(t_StackTraceElement *self, PyObject *args);
    static PyObject *t_StackTraceElement_isNativeMethod(t_StackTraceElement *self);
    static PyObject *t_StackTraceElement_toString(t_StackTraceElement *self, PyObject *args);
    static PyObject *t_StackTraceElement_get__className(t_StackTraceElement *self, void *data);
    static PyObject *t_StackTraceElement_get__fileName(t_StackTraceElement *self, void *data);
    static PyObject *t_StackTraceElement_get__lineNumber(t_StackTraceElement *self, void *data);
    static PyObject *t_StackTraceElement_get__methodName(t_StackTraceElement *self, void *data);
    static PyObject *t_StackTraceElement_get__nativeMethod(t_StackTraceElement *self, void *data);
    static PyGetSetDef t_StackTraceElement__fields_[] = {
      DECLARE_GET_FIELD(t_StackTraceElement, className),
      DECLARE_GET_FIELD(t_StackTraceElement, fileName),
      DECLARE_GET_FIELD(t_StackTraceElement, lineNumber),
      DECLARE_GET_FIELD(t_StackTraceElement, methodName),
      DECLARE_GET_FIELD(t_StackTraceElement, nativeMethod),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_StackTraceElement__methods_[] = {
      DECLARE_METHOD(t_StackTraceElement, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StackTraceElement, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StackTraceElement, equals, METH_VARARGS),
      DECLARE_METHOD(t_StackTraceElement, getClassName, METH_NOARGS),
      DECLARE_METHOD(t_StackTraceElement, getFileName, METH_NOARGS),
      DECLARE_METHOD(t_StackTraceElement, getLineNumber, METH_NOARGS),
      DECLARE_METHOD(t_StackTraceElement, getMethodName, METH_NOARGS),
      DECLARE_METHOD(t_StackTraceElement, hashCode, METH_VARARGS),
      DECLARE_METHOD(t_StackTraceElement, isNativeMethod, METH_NOARGS),
      DECLARE_METHOD(t_StackTraceElement, toString, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(StackTraceElement, t_StackTraceElement, ::java::lang::Object, StackTraceElement, t_StackTraceElement_init_, 0, 0, t_StackTraceElement__fields_, 0, 0);

    void t_StackTraceElement::install(PyObject *module)
    {
      installType(&PY_TYPE(StackTraceElement), module, "StackTraceElement", 0);
    }

    void t_StackTraceElement::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(StackTraceElement).tp_dict, "class_", make_descriptor(StackTraceElement::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(StackTraceElement).tp_dict, "wrapfn_", make_descriptor(t_StackTraceElement::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(StackTraceElement).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_StackTraceElement_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, StackTraceElement::initializeClass, 1)))
        return NULL;
      return t_StackTraceElement::wrap_Object(StackTraceElement(((t_StackTraceElement *) arg)->object.this$));
    }
    static PyObject *t_StackTraceElement_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, StackTraceElement::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_StackTraceElement_init_(t_StackTraceElement *self, PyObject *args, PyObject *kwds)
    {
      ::java::lang::String a0((jobject) NULL);
      ::java::lang::String a1((jobject) NULL);
      ::java::lang::String a2((jobject) NULL);
      jint a3;
      StackTraceElement object((jobject) NULL);

      if (!parseArgs(args, "sssI", &a0, &a1, &a2, &a3))
      {
        INT_CALL(object = StackTraceElement(a0, a1, a2, a3));
        self->object = object;
      }
      else
      {
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_StackTraceElement_equals(t_StackTraceElement *self, PyObject *args)
    {
      ::java::lang::Object a0((jobject) NULL);
      jboolean result;

      if (!parseArgs(args, "o", &a0))
      {
        OBJ_CALL(result = self->object.equals(a0));
        Py_RETURN_BOOL(result);
      }

      return callSuper(&PY_TYPE(StackTraceElement), (PyObject *) self, "equals", args, 2);
    }

    static PyObject *t_StackTraceElement_getClassName(t_StackTraceElement *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getClassName());
      return j2p(result);
    }

    static PyObject *t_StackTraceElement_getFileName(t_StackTraceElement *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getFileName());
      return j2p(result);
    }

    static PyObject *t_StackTraceElement_getLineNumber(t_StackTraceElement *self)
    {
      jint result;
      OBJ_CALL(result = self->object.getLineNumber());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_StackTraceElement_getMethodName(t_StackTraceElement *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getMethodName());
      return j2p(result);
    }

    static PyObject *t_StackTraceElement_hashCode(t_StackTraceElement *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.hashCode());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(StackTraceElement), (PyObject *) self, "hashCode", args, 2);
    }

    static PyObject *t_StackTraceElement_isNativeMethod(t_StackTraceElement *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isNativeMethod());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_StackTraceElement_toString(t_StackTraceElement *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(StackTraceElement), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_StackTraceElement_get__className(t_StackTraceElement *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getClassName());
      return j2p(value);
    }

    static PyObject *t_StackTraceElement_get__fileName(t_StackTraceElement *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getFileName());
      return j2p(value);
    }

    static PyObject *t_StackTraceElement_get__lineNumber(t_StackTraceElement *self, void *data)
    {
      jint value;
      OBJ_CALL(value = self->object.getLineNumber());
      return PyInt_FromLong((long) value);
    }

    static PyObject *t_StackTraceElement_get__methodName(t_StackTraceElement *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getMethodName());
      return j2p(value);
    }

    static PyObject *t_StackTraceElement_get__nativeMethod(t_StackTraceElement *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isNativeMethod());
      Py_RETURN_BOOL(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/IllegalAccessException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *IllegalAccessException::class$ = NULL;
    jmethodID *IllegalAccessException::mids$ = NULL;
    bool IllegalAccessException::live$ = false;

    jclass IllegalAccessException::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/IllegalAccessException");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    IllegalAccessException::IllegalAccessException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    IllegalAccessException::IllegalAccessException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_IllegalAccessException_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_IllegalAccessException_instance_(PyTypeObject *type, PyObject *arg);
    static int t_IllegalAccessException_init_(t_IllegalAccessException *self, PyObject *args, PyObject *kwds);

    static PyMethodDef t_IllegalAccessException__methods_[] = {
      DECLARE_METHOD(t_IllegalAccessException, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_IllegalAccessException, instance_, METH_O | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(IllegalAccessException, t_IllegalAccessException, ::java::lang::Exception, IllegalAccessException, t_IllegalAccessException_init_, 0, 0, 0, 0, 0);

    void t_IllegalAccessException::install(PyObject *module)
    {
      installType(&PY_TYPE(IllegalAccessException), module, "IllegalAccessException", 0);
    }

    void t_IllegalAccessException::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(IllegalAccessException).tp_dict, "class_", make_descriptor(IllegalAccessException::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(IllegalAccessException).tp_dict, "wrapfn_", make_descriptor(t_IllegalAccessException::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(IllegalAccessException).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_IllegalAccessException_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, IllegalAccessException::initializeClass, 1)))
        return NULL;
      return t_IllegalAccessException::wrap_Object(IllegalAccessException(((t_IllegalAccessException *) arg)->object.this$));
    }
    static PyObject *t_IllegalAccessException_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, IllegalAccessException::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_IllegalAccessException_init_(t_IllegalAccessException *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          IllegalAccessException object((jobject) NULL);

          INT_CALL(object = IllegalAccessException());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          IllegalAccessException object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = IllegalAccessException(a0));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Package.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Package::class$ = NULL;
    jmethodID *Package::mids$ = NULL;
    bool Package::live$ = false;

    jclass Package::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Package");

        mids$ = new jmethodID[max_mid];
        mids$[mid_getImplementationTitle_14c7b5c5] = env->getMethodID(cls, "getImplementationTitle", "()Ljava/lang/String;");
        mids$[mid_getImplementationVendor_14c7b5c5] = env->getMethodID(cls, "getImplementationVendor", "()Ljava/lang/String;");
        mids$[mid_getImplementationVersion_14c7b5c5] = env->getMethodID(cls, "getImplementationVersion", "()Ljava/lang/String;");
        mids$[mid_getName_14c7b5c5] = env->getMethodID(cls, "getName", "()Ljava/lang/String;");
        mids$[mid_getPackage_d9fbaba1] = env->getStaticMethodID(cls, "getPackage", "(Ljava/lang/String;)Ljava/lang/Package;");
        mids$[mid_getPackages_c03e7c17] = env->getStaticMethodID(cls, "getPackages", "()[Ljava/lang/Package;");
        mids$[mid_getSpecificationTitle_14c7b5c5] = env->getMethodID(cls, "getSpecificationTitle", "()Ljava/lang/String;");
        mids$[mid_getSpecificationVendor_14c7b5c5] = env->getMethodID(cls, "getSpecificationVendor", "()Ljava/lang/String;");
        mids$[mid_getSpecificationVersion_14c7b5c5] = env->getMethodID(cls, "getSpecificationVersion", "()Ljava/lang/String;");
        mids$[mid_hashCode_54c6a179] = env->getMethodID(cls, "hashCode", "()I");
        mids$[mid_isCompatibleWith_5fdc3f44] = env->getMethodID(cls, "isCompatibleWith", "(Ljava/lang/String;)Z");
        mids$[mid_isSealed_54c6a16a] = env->getMethodID(cls, "isSealed", "()Z");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    ::java::lang::String Package::getImplementationTitle() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getImplementationTitle_14c7b5c5]));
    }

    ::java::lang::String Package::getImplementationVendor() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getImplementationVendor_14c7b5c5]));
    }

    ::java::lang::String Package::getImplementationVersion() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getImplementationVersion_14c7b5c5]));
    }

    ::java::lang::String Package::getName() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getName_14c7b5c5]));
    }

    Package Package::getPackage(const ::java::lang::String & a0)
    {
      jclass cls = env->getClass(initializeClass);
      return Package(env->callStaticObjectMethod(cls, mids$[mid_getPackage_d9fbaba1], a0.this$));
    }

    JArray< Package > Package::getPackages()
    {
      jclass cls = env->getClass(initializeClass);
      return JArray< Package >(env->callStaticObjectMethod(cls, mids$[mid_getPackages_c03e7c17]));
    }

    ::java::lang::String Package::getSpecificationTitle() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSpecificationTitle_14c7b5c5]));
    }

    ::java::lang::String Package::getSpecificationVendor() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSpecificationVendor_14c7b5c5]));
    }

    ::java::lang::String Package::getSpecificationVersion() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_getSpecificationVersion_14c7b5c5]));
    }

    jint Package::hashCode() const
    {
      return env->callIntMethod(this$, mids$[mid_hashCode_54c6a179]);
    }

    jboolean Package::isCompatibleWith(const ::java::lang::String & a0) const
    {
      return env->callBooleanMethod(this$, mids$[mid_isCompatibleWith_5fdc3f44], a0.this$);
    }

    jboolean Package::isSealed() const
    {
      return env->callBooleanMethod(this$, mids$[mid_isSealed_54c6a16a]);
    }

    ::java::lang::String Package::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Package_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Package_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Package_getImplementationTitle(t_Package *self);
    static PyObject *t_Package_getImplementationVendor(t_Package *self);
    static PyObject *t_Package_getImplementationVersion(t_Package *self);
    static PyObject *t_Package_getName(t_Package *self);
    static PyObject *t_Package_getPackage(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Package_getPackages(PyTypeObject *type);
    static PyObject *t_Package_getSpecificationTitle(t_Package *self);
    static PyObject *t_Package_getSpecificationVendor(t_Package *self);
    static PyObject *t_Package_getSpecificationVersion(t_Package *self);
    static PyObject *t_Package_hashCode(t_Package *self, PyObject *args);
    static PyObject *t_Package_isCompatibleWith(t_Package *self, PyObject *arg);
    static PyObject *t_Package_isSealed(t_Package *self);
    static PyObject *t_Package_toString(t_Package *self, PyObject *args);
    static PyObject *t_Package_get__implementationTitle(t_Package *self, void *data);
    static PyObject *t_Package_get__implementationVendor(t_Package *self, void *data);
    static PyObject *t_Package_get__implementationVersion(t_Package *self, void *data);
    static PyObject *t_Package_get__name(t_Package *self, void *data);
    static PyObject *t_Package_get__packages(t_Package *self, void *data);
    static PyObject *t_Package_get__sealed(t_Package *self, void *data);
    static PyObject *t_Package_get__specificationTitle(t_Package *self, void *data);
    static PyObject *t_Package_get__specificationVendor(t_Package *self, void *data);
    static PyObject *t_Package_get__specificationVersion(t_Package *self, void *data);
    static PyGetSetDef t_Package__fields_[] = {
      DECLARE_GET_FIELD(t_Package, implementationTitle),
      DECLARE_GET_FIELD(t_Package, implementationVendor),
      DECLARE_GET_FIELD(t_Package, implementationVersion),
      DECLARE_GET_FIELD(t_Package, name),
      DECLARE_GET_FIELD(t_Package, packages),
      DECLARE_GET_FIELD(t_Package, sealed),
      DECLARE_GET_FIELD(t_Package, specificationTitle),
      DECLARE_GET_FIELD(t_Package, specificationVendor),
      DECLARE_GET_FIELD(t_Package, specificationVersion),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Package__methods_[] = {
      DECLARE_METHOD(t_Package, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Package, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Package, getImplementationTitle, METH_NOARGS),
      DECLARE_METHOD(t_Package, getImplementationVendor, METH_NOARGS),
      DECLARE_METHOD(t_Package, getImplementationVersion, METH_NOARGS),
      DECLARE_METHOD(t_Package, getName, METH_NOARGS),
      DECLARE_METHOD(t_Package, getPackage, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Package, getPackages, METH_NOARGS | METH_CLASS),
      DECLARE_METHOD(t_Package, getSpecificationTitle, METH_NOARGS),
      DECLARE_METHOD(t_Package, getSpecificationVendor, METH_NOARGS),
      DECLARE_METHOD(t_Package, getSpecificationVersion, METH_NOARGS),
      DECLARE_METHOD(t_Package, hashCode, METH_VARARGS),
      DECLARE_METHOD(t_Package, isCompatibleWith, METH_O),
      DECLARE_METHOD(t_Package, isSealed, METH_NOARGS),
      DECLARE_METHOD(t_Package, toString, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Package, t_Package, ::java::lang::Object, Package, abstract_init, 0, 0, t_Package__fields_, 0, 0);

    void t_Package::install(PyObject *module)
    {
      installType(&PY_TYPE(Package), module, "Package", 0);
    }

    void t_Package::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Package).tp_dict, "class_", make_descriptor(Package::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Package).tp_dict, "wrapfn_", make_descriptor(t_Package::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Package).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Package_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Package::initializeClass, 1)))
        return NULL;
      return t_Package::wrap_Object(Package(((t_Package *) arg)->object.this$));
    }
    static PyObject *t_Package_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Package::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_Package_getImplementationTitle(t_Package *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getImplementationTitle());
      return j2p(result);
    }

    static PyObject *t_Package_getImplementationVendor(t_Package *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getImplementationVendor());
      return j2p(result);
    }

    static PyObject *t_Package_getImplementationVersion(t_Package *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getImplementationVersion());
      return j2p(result);
    }

    static PyObject *t_Package_getName(t_Package *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getName());
      return j2p(result);
    }

    static PyObject *t_Package_getPackage(PyTypeObject *type, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      Package result((jobject) NULL);

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = ::java::lang::Package::getPackage(a0));
        return t_Package::wrap_Object(result);
      }

      PyErr_SetArgsError(type, "getPackage", arg);
      return NULL;
    }

    static PyObject *t_Package_getPackages(PyTypeObject *type)
    {
      JArray< Package > result((jobject) NULL);
      OBJ_CALL(result = ::java::lang::Package::getPackages());
      return JArray<jobject>(result.this$).wrap(t_Package::wrap_jobject);
    }

    static PyObject *t_Package_getSpecificationTitle(t_Package *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getSpecificationTitle());
      return j2p(result);
    }

    static PyObject *t_Package_getSpecificationVendor(t_Package *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getSpecificationVendor());
      return j2p(result);
    }

    static PyObject *t_Package_getSpecificationVersion(t_Package *self)
    {
      ::java::lang::String result((jobject) NULL);
      OBJ_CALL(result = self->object.getSpecificationVersion());
      return j2p(result);
    }

    static PyObject *t_Package_hashCode(t_Package *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.hashCode());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(Package), (PyObject *) self, "hashCode", args, 2);
    }

    static PyObject *t_Package_isCompatibleWith(t_Package *self, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      jboolean result;

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = self->object.isCompatibleWith(a0));
        Py_RETURN_BOOL(result);
      }

      PyErr_SetArgsError((PyObject *) self, "isCompatibleWith", arg);
      return NULL;
    }

    static PyObject *t_Package_isSealed(t_Package *self)
    {
      jboolean result;
      OBJ_CALL(result = self->object.isSealed());
      Py_RETURN_BOOL(result);
    }

    static PyObject *t_Package_toString(t_Package *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(Package), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_Package_get__implementationTitle(t_Package *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getImplementationTitle());
      return j2p(value);
    }

    static PyObject *t_Package_get__implementationVendor(t_Package *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getImplementationVendor());
      return j2p(value);
    }

    static PyObject *t_Package_get__implementationVersion(t_Package *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getImplementationVersion());
      return j2p(value);
    }

    static PyObject *t_Package_get__name(t_Package *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getName());
      return j2p(value);
    }

    static PyObject *t_Package_get__packages(t_Package *self, void *data)
    {
      JArray< Package > value((jobject) NULL);
      OBJ_CALL(value = self->object.getPackages());
      return JArray<jobject>(value.this$).wrap(t_Package::wrap_jobject);
    }

    static PyObject *t_Package_get__sealed(t_Package *self, void *data)
    {
      jboolean value;
      OBJ_CALL(value = self->object.isSealed());
      Py_RETURN_BOOL(value);
    }

    static PyObject *t_Package_get__specificationTitle(t_Package *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getSpecificationTitle());
      return j2p(value);
    }

    static PyObject *t_Package_get__specificationVendor(t_Package *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getSpecificationVendor());
      return j2p(value);
    }

    static PyObject *t_Package_get__specificationVersion(t_Package *self, void *data)
    {
      ::java::lang::String value((jobject) NULL);
      OBJ_CALL(value = self->object.getSpecificationVersion());
      return j2p(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/CharSequence.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *CharSequence::class$ = NULL;
    jmethodID *CharSequence::mids$ = NULL;
    bool CharSequence::live$ = false;

    jclass CharSequence::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/CharSequence");

        mids$ = new jmethodID[max_mid];
        mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
        mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
        mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    jchar CharSequence::charAt(jint a0) const
    {
      return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
    }

    jint CharSequence::length() const
    {
      return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
    }

    CharSequence CharSequence::subSequence(jint a0, jint a1) const
    {
      return CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
    }

    ::java::lang::String CharSequence::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_CharSequence_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_CharSequence_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_CharSequence_charAt(t_CharSequence *self, PyObject *arg);
    static PyObject *t_CharSequence_length(t_CharSequence *self);
    static PyObject *t_CharSequence_subSequence(t_CharSequence *self, PyObject *args);
    static PyObject *t_CharSequence_toString(t_CharSequence *self, PyObject *args);

    static PyMethodDef t_CharSequence__methods_[] = {
      DECLARE_METHOD(t_CharSequence, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_CharSequence, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_CharSequence, charAt, METH_O),
      DECLARE_METHOD(t_CharSequence, length, METH_NOARGS),
      DECLARE_METHOD(t_CharSequence, subSequence, METH_VARARGS),
      DECLARE_METHOD(t_CharSequence, toString, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(CharSequence, t_CharSequence, ::java::lang::Object, CharSequence, abstract_init, 0, 0, 0, 0, 0);

    void t_CharSequence::install(PyObject *module)
    {
      installType(&PY_TYPE(CharSequence), module, "CharSequence", 0);
    }

    void t_CharSequence::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(CharSequence).tp_dict, "class_", make_descriptor(CharSequence::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(CharSequence).tp_dict, "wrapfn_", make_descriptor(t_CharSequence::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(CharSequence).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_CharSequence_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, CharSequence::initializeClass, 1)))
        return NULL;
      return t_CharSequence::wrap_Object(CharSequence(((t_CharSequence *) arg)->object.this$));
    }
    static PyObject *t_CharSequence_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, CharSequence::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_CharSequence_charAt(t_CharSequence *self, PyObject *arg)
    {
      jint a0;
      jchar result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = self->object.charAt(a0));
        return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
      }

      PyErr_SetArgsError((PyObject *) self, "charAt", arg);
      return NULL;
    }

    static PyObject *t_CharSequence_length(t_CharSequence *self)
    {
      jint result;
      OBJ_CALL(result = self->object.length());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_CharSequence_subSequence(t_CharSequence *self, PyObject *args)
    {
      jint a0;
      jint a1;
      CharSequence result((jobject) NULL);

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.subSequence(a0, a1));
        return t_CharSequence::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "subSequence", args);
      return NULL;
    }

    static PyObject *t_CharSequence_toString(t_CharSequence *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(CharSequence), (PyObject *) self, "toString", args, 2);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/Object.h"
#include "java/lang/CharSequence.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *StringBuffer::class$ = NULL;
    jmethodID *StringBuffer::mids$ = NULL;
    bool StringBuffer::live$ = false;

    jclass StringBuffer::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/StringBuffer");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_init$_a8afc64a] = env->getMethodID(cls, "<init>", "(Ljava/lang/CharSequence;)V");
        mids$[mid_append_35d2e845] = env->getMethodID(cls, "append", "([C)Ljava/lang/StringBuffer;");
        mids$[mid_append_251e110e] = env->getMethodID(cls, "append", "(F)Ljava/lang/StringBuffer;");
        mids$[mid_append_24b69bf0] = env->getMethodID(cls, "append", "(D)Ljava/lang/StringBuffer;");
        mids$[mid_append_67ad01ed] = env->getMethodID(cls, "append", "(Ljava/lang/Object;)Ljava/lang/StringBuffer;");
        mids$[mid_append_662d52ca] = env->getMethodID(cls, "append", "(J)Ljava/lang/StringBuffer;");
        mids$[mid_append_bb3a365a] = env->getMethodID(cls, "append", "(Z)Ljava/lang/StringBuffer;");
        mids$[mid_append_4ca72be1] = env->getMethodID(cls, "append", "(C)Ljava/lang/StringBuffer;");
        mids$[mid_append_6b1920e9] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuffer;");
        mids$[mid_append_2979b2bb] = env->getMethodID(cls, "append", "(Ljava/lang/String;)Ljava/lang/StringBuffer;");
        mids$[mid_append_fdff3523] = env->getMethodID(cls, "append", "(I)Ljava/lang/StringBuffer;");
        mids$[mid_append_a876a4ab] = env->getMethodID(cls, "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuffer;");
        mids$[mid_append_aa3a4fc5] = env->getMethodID(cls, "append", "([CII)Ljava/lang/StringBuffer;");
        mids$[mid_append_f3c776b1] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
        mids$[mid_appendCodePoint_fdff3523] = env->getMethodID(cls, "appendCodePoint", "(I)Ljava/lang/StringBuffer;");
        mids$[mid_capacity_54c6a179] = env->getMethodID(cls, "capacity", "()I");
        mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
        mids$[mid_codePointAt_39c7bd23] = env->getMethodID(cls, "codePointAt", "(I)I");
        mids$[mid_codePointBefore_39c7bd23] = env->getMethodID(cls, "codePointBefore", "(I)I");
        mids$[mid_codePointCount_d8d154b9] = env->getMethodID(cls, "codePointCount", "(II)I");
        mids$[mid_delete_644727d5] = env->getMethodID(cls, "delete", "(II)Ljava/lang/StringBuffer;");
        mids$[mid_deleteCharAt_fdff3523] = env->getMethodID(cls, "deleteCharAt", "(I)Ljava/lang/StringBuffer;");
        mids$[mid_ensureCapacity_39c7bd3c] = env->getMethodID(cls, "ensureCapacity", "(I)V");
        mids$[mid_getChars_06518f84] = env->getMethodID(cls, "getChars", "(II[CI)V");
        mids$[mid_indexOf_5fdc3f57] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;)I");
        mids$[mid_indexOf_6e53ccd9] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;I)I");
        mids$[mid_insert_d95ec358] = env->getMethodID(cls, "insert", "(IF)Ljava/lang/StringBuffer;");
        mids$[mid_insert_bc0ebac7] = env->getMethodID(cls, "insert", "(I[C)Ljava/lang/StringBuffer;");
        mids$[mid_insert_88877b15] = env->getMethodID(cls, "insert", "(ILjava/lang/String;)Ljava/lang/StringBuffer;");
        mids$[mid_insert_644727d5] = env->getMethodID(cls, "insert", "(II)Ljava/lang/StringBuffer;");
        mids$[mid_insert_b71b2a52] = env->getMethodID(cls, "insert", "(ID)Ljava/lang/StringBuffer;");
        mids$[mid_insert_2e164a03] = env->getMethodID(cls, "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuffer;");
        mids$[mid_insert_ed5f9c37] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuffer;");
        mids$[mid_insert_3c3656bc] = env->getMethodID(cls, "insert", "(IZ)Ljava/lang/StringBuffer;");
        mids$[mid_insert_3d91488b] = env->getMethodID(cls, "insert", "(IC)Ljava/lang/StringBuffer;");
        mids$[mid_insert_5e363fec] = env->getMethodID(cls, "insert", "(IJ)Ljava/lang/StringBuffer;");
        mids$[mid_insert_732cbadf] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuffer;");
        mids$[mid_insert_6edd3397] = env->getMethodID(cls, "insert", "(I[CII)Ljava/lang/StringBuffer;");
        mids$[mid_lastIndexOf_5fdc3f57] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;)I");
        mids$[mid_lastIndexOf_6e53ccd9] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;I)I");
        mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
        mids$[mid_offsetByCodePoints_d8d154b9] = env->getMethodID(cls, "offsetByCodePoints", "(II)I");
        mids$[mid_replace_95b69603] = env->getMethodID(cls, "replace", "(IILjava/lang/String;)Ljava/lang/StringBuffer;");
        mids$[mid_reverse_d54172a5] = env->getMethodID(cls, "reverse", "()Ljava/lang/StringBuffer;");
        mids$[mid_setCharAt_83eec158] = env->getMethodID(cls, "setCharAt", "(IC)V");
        mids$[mid_setLength_39c7bd3c] = env->getMethodID(cls, "setLength", "(I)V");
        mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
        mids$[mid_substring_141401b3] = env->getMethodID(cls, "substring", "(I)Ljava/lang/String;");
        mids$[mid_substring_f9118fe5] = env->getMethodID(cls, "substring", "(II)Ljava/lang/String;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_trimToSize_54c6a166] = env->getMethodID(cls, "trimToSize", "()V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    StringBuffer::StringBuffer() : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    StringBuffer::StringBuffer(jint a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

    StringBuffer::StringBuffer(const ::java::lang::String & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    StringBuffer::StringBuffer(const ::java::lang::CharSequence & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_a8afc64a, a0.this$)) {}

    StringBuffer StringBuffer::append(const JArray< jchar > & a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_35d2e845], a0.this$));
    }

    StringBuffer StringBuffer::append(jfloat a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_251e110e], a0));
    }

    StringBuffer StringBuffer::append(jdouble a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_24b69bf0], a0));
    }

    StringBuffer StringBuffer::append(const ::java::lang::Object & a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_67ad01ed], a0.this$));
    }

    StringBuffer StringBuffer::append(jlong a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_662d52ca], a0));
    }

    StringBuffer StringBuffer::append(jboolean a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_bb3a365a], a0));
    }

    StringBuffer StringBuffer::append(jchar a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_4ca72be1], a0));
    }

    StringBuffer StringBuffer::append(const ::java::lang::CharSequence & a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_6b1920e9], a0.this$));
    }

    StringBuffer StringBuffer::append(const ::java::lang::String & a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_2979b2bb], a0.this$));
    }

    StringBuffer StringBuffer::append(jint a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_fdff3523], a0));
    }

    StringBuffer StringBuffer::append(const StringBuffer & a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_a876a4ab], a0.this$));
    }

    StringBuffer StringBuffer::append(const JArray< jchar > & a0, jint a1, jint a2) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_aa3a4fc5], a0.this$, a1, a2));
    }

    StringBuffer StringBuffer::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_append_f3c776b1], a0.this$, a1, a2));
    }

    StringBuffer StringBuffer::appendCodePoint(jint a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_appendCodePoint_fdff3523], a0));
    }

    jint StringBuffer::capacity() const
    {
      return env->callIntMethod(this$, mids$[mid_capacity_54c6a179]);
    }

    jchar StringBuffer::charAt(jint a0) const
    {
      return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
    }

    jint StringBuffer::codePointAt(jint a0) const
    {
      return env->callIntMethod(this$, mids$[mid_codePointAt_39c7bd23], a0);
    }

    jint StringBuffer::codePointBefore(jint a0) const
    {
      return env->callIntMethod(this$, mids$[mid_codePointBefore_39c7bd23], a0);
    }

    jint StringBuffer::codePointCount(jint a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_codePointCount_d8d154b9], a0, a1);
    }

    StringBuffer StringBuffer::delete$(jint a0, jint a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_delete_644727d5], a0, a1));
    }

    StringBuffer StringBuffer::deleteCharAt(jint a0) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_deleteCharAt_fdff3523], a0));
    }

    void StringBuffer::ensureCapacity(jint a0) const
    {
      env->callVoidMethod(this$, mids$[mid_ensureCapacity_39c7bd3c], a0);
    }

    void StringBuffer::getChars(jint a0, jint a1, const JArray< jchar > & a2, jint a3) const
    {
      env->callVoidMethod(this$, mids$[mid_getChars_06518f84], a0, a1, a2.this$, a3);
    }

    jint StringBuffer::indexOf(const ::java::lang::String & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_indexOf_5fdc3f57], a0.this$);
    }

    jint StringBuffer::indexOf(const ::java::lang::String & a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_indexOf_6e53ccd9], a0.this$, a1);
    }

    StringBuffer StringBuffer::insert(jint a0, jfloat a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_d95ec358], a0, a1));
    }

    StringBuffer StringBuffer::insert(jint a0, const JArray< jchar > & a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_bc0ebac7], a0, a1.this$));
    }

    StringBuffer StringBuffer::insert(jint a0, const ::java::lang::String & a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_88877b15], a0, a1.this$));
    }

    StringBuffer StringBuffer::insert(jint a0, jint a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_644727d5], a0, a1));
    }

    StringBuffer StringBuffer::insert(jint a0, jdouble a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_b71b2a52], a0, a1));
    }

    StringBuffer StringBuffer::insert(jint a0, const ::java::lang::Object & a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_2e164a03], a0, a1.this$));
    }

    StringBuffer StringBuffer::insert(jint a0, const ::java::lang::CharSequence & a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_ed5f9c37], a0, a1.this$));
    }

    StringBuffer StringBuffer::insert(jint a0, jboolean a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_3c3656bc], a0, a1));
    }

    StringBuffer StringBuffer::insert(jint a0, jchar a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_3d91488b], a0, a1));
    }

    StringBuffer StringBuffer::insert(jint a0, jlong a1) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_5e363fec], a0, a1));
    }

    StringBuffer StringBuffer::insert(jint a0, const ::java::lang::CharSequence & a1, jint a2, jint a3) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_732cbadf], a0, a1.this$, a2, a3));
    }

    StringBuffer StringBuffer::insert(jint a0, const JArray< jchar > & a1, jint a2, jint a3) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_insert_6edd3397], a0, a1.this$, a2, a3));
    }

    jint StringBuffer::lastIndexOf(const ::java::lang::String & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_lastIndexOf_5fdc3f57], a0.this$);
    }

    jint StringBuffer::lastIndexOf(const ::java::lang::String & a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_lastIndexOf_6e53ccd9], a0.this$, a1);
    }

    jint StringBuffer::length() const
    {
      return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
    }

    jint StringBuffer::offsetByCodePoints(jint a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_offsetByCodePoints_d8d154b9], a0, a1);
    }

    StringBuffer StringBuffer::replace(jint a0, jint a1, const ::java::lang::String & a2) const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_replace_95b69603], a0, a1, a2.this$));
    }

    StringBuffer StringBuffer::reverse() const
    {
      return StringBuffer(env->callObjectMethod(this$, mids$[mid_reverse_d54172a5]));
    }

    void StringBuffer::setCharAt(jint a0, jchar a1) const
    {
      env->callVoidMethod(this$, mids$[mid_setCharAt_83eec158], a0, a1);
    }

    void StringBuffer::setLength(jint a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setLength_39c7bd3c], a0);
    }

    ::java::lang::CharSequence StringBuffer::subSequence(jint a0, jint a1) const
    {
      return ::java::lang::CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
    }

    ::java::lang::String StringBuffer::substring(jint a0) const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_141401b3], a0));
    }

    ::java::lang::String StringBuffer::substring(jint a0, jint a1) const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_f9118fe5], a0, a1));
    }

    ::java::lang::String StringBuffer::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    void StringBuffer::trimToSize() const
    {
      env->callVoidMethod(this$, mids$[mid_trimToSize_54c6a166]);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_StringBuffer_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_StringBuffer_instance_(PyTypeObject *type, PyObject *arg);
    static int t_StringBuffer_init_(t_StringBuffer *self, PyObject *args, PyObject *kwds);
    static PyObject *t_StringBuffer_append(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_appendCodePoint(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_capacity(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_charAt(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_codePointAt(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_codePointBefore(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_codePointCount(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_delete(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_deleteCharAt(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_ensureCapacity(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_getChars(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_indexOf(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_insert(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_lastIndexOf(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_length(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_offsetByCodePoints(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_replace(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_reverse(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_setCharAt(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_setLength(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_subSequence(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_substring(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_toString(t_StringBuffer *self, PyObject *args);
    static PyObject *t_StringBuffer_trimToSize(t_StringBuffer *self, PyObject *args);

    static PyMethodDef t_StringBuffer__methods_[] = {
      DECLARE_METHOD(t_StringBuffer, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StringBuffer, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StringBuffer, append, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, appendCodePoint, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, capacity, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, charAt, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, codePointAt, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, codePointBefore, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, codePointCount, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, delete, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, deleteCharAt, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, ensureCapacity, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, getChars, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, indexOf, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, insert, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, lastIndexOf, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, length, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, offsetByCodePoints, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, replace, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, reverse, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, setCharAt, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, setLength, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, subSequence, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, substring, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, toString, METH_VARARGS),
      DECLARE_METHOD(t_StringBuffer, trimToSize, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(StringBuffer, t_StringBuffer, ::java::lang::AbstractStringBuilder, StringBuffer, t_StringBuffer_init_, 0, 0, 0, 0, 0);

    void t_StringBuffer::install(PyObject *module)
    {
      installType(&PY_TYPE(StringBuffer), module, "StringBuffer", 0);
    }

    void t_StringBuffer::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(StringBuffer).tp_dict, "class_", make_descriptor(StringBuffer::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(StringBuffer).tp_dict, "wrapfn_", make_descriptor(t_StringBuffer::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(StringBuffer).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_StringBuffer_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, StringBuffer::initializeClass, 1)))
        return NULL;
      return t_StringBuffer::wrap_Object(StringBuffer(((t_StringBuffer *) arg)->object.this$));
    }
    static PyObject *t_StringBuffer_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, StringBuffer::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_StringBuffer_init_(t_StringBuffer *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          StringBuffer object((jobject) NULL);

          INT_CALL(object = StringBuffer());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          jint a0;
          StringBuffer object((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            INT_CALL(object = StringBuffer(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          StringBuffer object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = StringBuffer(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          StringBuffer object((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            INT_CALL(object = StringBuffer(a0));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_StringBuffer_append(t_StringBuffer *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          JArray< jchar > a0((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "[C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jfloat a0;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "F", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jdouble a0;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "D", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          ::java::lang::Object a0((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "o", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jlong a0;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "J", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jboolean a0;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "Z", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jchar a0;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          StringBuffer a0((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "k", StringBuffer::initializeClass, &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        break;
       case 3:
        {
          JArray< jchar > a0((jobject) NULL);
          jint a1;
          jint a2;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "[CII", &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          jint a1;
          jint a2;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_StringBuffer::wrap_Object(result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "append", args, 2);
    }

    static PyObject *t_StringBuffer_appendCodePoint(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      StringBuffer result((jobject) NULL);

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(result = self->object.appendCodePoint(a0));
        return t_StringBuffer::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "appendCodePoint", args, 2);
    }

    static PyObject *t_StringBuffer_capacity(t_StringBuffer *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.capacity());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "capacity", args, 2);
    }

    static PyObject *t_StringBuffer_charAt(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jchar result;

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(result = self->object.charAt(a0));
        return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "charAt", args, 2);
    }

    static PyObject *t_StringBuffer_codePointAt(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint result;

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(result = self->object.codePointAt(a0));
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "codePointAt", args, 2);
    }

    static PyObject *t_StringBuffer_codePointBefore(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint result;

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(result = self->object.codePointBefore(a0));
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "codePointBefore", args, 2);
    }

    static PyObject *t_StringBuffer_codePointCount(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint a1;
      jint result;

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.codePointCount(a0, a1));
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "codePointCount", args, 2);
    }

    static PyObject *t_StringBuffer_delete(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint a1;
      StringBuffer result((jobject) NULL);

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.delete$(a0, a1));
        return t_StringBuffer::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "delete", args, 2);
    }

    static PyObject *t_StringBuffer_deleteCharAt(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      StringBuffer result((jobject) NULL);

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(result = self->object.deleteCharAt(a0));
        return t_StringBuffer::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "deleteCharAt", args, 2);
    }

    static PyObject *t_StringBuffer_ensureCapacity(t_StringBuffer *self, PyObject *args)
    {
      jint a0;

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(self->object.ensureCapacity(a0));
        Py_RETURN_NONE;
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "ensureCapacity", args, 2);
    }

    static PyObject *t_StringBuffer_getChars(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint a1;
      JArray< jchar > a2((jobject) NULL);
      jint a3;

      if (!parseArgs(args, "II[CI", &a0, &a1, &a2, &a3))
      {
        OBJ_CALL(self->object.getChars(a0, a1, a2, a3));
        Py_RETURN_NONE;
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "getChars", args, 2);
    }

    static PyObject *t_StringBuffer_indexOf(t_StringBuffer *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jint result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.indexOf(a0));
            return PyInt_FromLong((long) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = self->object.indexOf(a0, a1));
            return PyInt_FromLong((long) result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "indexOf", args, 2);
    }

    static PyObject *t_StringBuffer_insert(t_StringBuffer *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 2:
        {
          jint a0;
          jfloat a1;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "IF", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          JArray< jchar > a1((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "I[C", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::String a1((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "Is", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          jint a1;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "II", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          jdouble a1;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "ID", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::Object a1((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "Io", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::CharSequence a1((jobject) NULL);
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "IO", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          jboolean a1;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "IZ", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          jchar a1;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "IC", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          jlong a1;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "IJ", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        break;
       case 4:
        {
          jint a0;
          ::java::lang::CharSequence a1((jobject) NULL);
          jint a2;
          jint a3;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "IOII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2, &a3))
          {
            OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
            return t_StringBuffer::wrap_Object(result);
          }
        }
        {
          jint a0;
          JArray< jchar > a1((jobject) NULL);
          jint a2;
          jint a3;
          StringBuffer result((jobject) NULL);

          if (!parseArgs(args, "I[CII", &a0, &a1, &a2, &a3))
          {
            OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
            return t_StringBuffer::wrap_Object(result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "insert", args, 2);
    }

    static PyObject *t_StringBuffer_lastIndexOf(t_StringBuffer *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jint result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.lastIndexOf(a0));
            return PyInt_FromLong((long) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
            return PyInt_FromLong((long) result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "lastIndexOf", args, 2);
    }

    static PyObject *t_StringBuffer_length(t_StringBuffer *self, PyObject *args)
    {
      jint result;

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.length());
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "length", args, 2);
    }

    static PyObject *t_StringBuffer_offsetByCodePoints(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint a1;
      jint result;

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.offsetByCodePoints(a0, a1));
        return PyInt_FromLong((long) result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "offsetByCodePoints", args, 2);
    }

    static PyObject *t_StringBuffer_replace(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint a1;
      ::java::lang::String a2((jobject) NULL);
      StringBuffer result((jobject) NULL);

      if (!parseArgs(args, "IIs", &a0, &a1, &a2))
      {
        OBJ_CALL(result = self->object.replace(a0, a1, a2));
        return t_StringBuffer::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "replace", args, 2);
    }

    static PyObject *t_StringBuffer_reverse(t_StringBuffer *self, PyObject *args)
    {
      StringBuffer result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.reverse());
        return t_StringBuffer::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "reverse", args, 2);
    }

    static PyObject *t_StringBuffer_setCharAt(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jchar a1;

      if (!parseArgs(args, "IC", &a0, &a1))
      {
        OBJ_CALL(self->object.setCharAt(a0, a1));
        Py_RETURN_NONE;
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "setCharAt", args, 2);
    }

    static PyObject *t_StringBuffer_setLength(t_StringBuffer *self, PyObject *args)
    {
      jint a0;

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(self->object.setLength(a0));
        Py_RETURN_NONE;
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "setLength", args, 2);
    }

    static PyObject *t_StringBuffer_subSequence(t_StringBuffer *self, PyObject *args)
    {
      jint a0;
      jint a1;
      ::java::lang::CharSequence result((jobject) NULL);

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.subSequence(a0, a1));
        return ::java::lang::t_CharSequence::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "subSequence", args, 2);
    }

    static PyObject *t_StringBuffer_substring(t_StringBuffer *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jint a0;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(result = self->object.substring(a0));
            return j2p(result);
          }
        }
        break;
       case 2:
        {
          jint a0;
          jint a1;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "II", &a0, &a1))
          {
            OBJ_CALL(result = self->object.substring(a0, a1));
            return j2p(result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "substring", args, 2);
    }

    static PyObject *t_StringBuffer_toString(t_StringBuffer *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_StringBuffer_trimToSize(t_StringBuffer *self, PyObject *args)
    {

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(self->object.trimToSize());
        Py_RETURN_NONE;
      }

      return callSuper(&PY_TYPE(StringBuffer), (PyObject *) self, "trimToSize", args, 2);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/ClassLoader.h"
#include "java/lang/String.h"
#include "java/util/Enumeration.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *ClassLoader::class$ = NULL;
    jmethodID *ClassLoader::mids$ = NULL;
    bool ClassLoader::live$ = false;

    jclass ClassLoader::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/ClassLoader");

        mids$ = new jmethodID[max_mid];
        mids$[mid_clearAssertionStatus_54c6a166] = env->getMethodID(cls, "clearAssertionStatus", "()V");
        mids$[mid_getParent_8d2f11fc] = env->getMethodID(cls, "getParent", "()Ljava/lang/ClassLoader;");
        mids$[mid_getSystemClassLoader_8d2f11fc] = env->getStaticMethodID(cls, "getSystemClassLoader", "()Ljava/lang/ClassLoader;");
        mids$[mid_loadClass_7d663d97] = env->getMethodID(cls, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");
        mids$[mid_setClassAssertionStatus_f3691645] = env->getMethodID(cls, "setClassAssertionStatus", "(Ljava/lang/String;Z)V");
        mids$[mid_setDefaultAssertionStatus_bb0c767f] = env->getMethodID(cls, "setDefaultAssertionStatus", "(Z)V");
        mids$[mid_setPackageAssertionStatus_f3691645] = env->getMethodID(cls, "setPackageAssertionStatus", "(Ljava/lang/String;Z)V");
        mids$[mid_loadClass_dfdc0682] = env->getMethodID(cls, "loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;");
        mids$[mid_getPackage_d9fbaba1] = env->getMethodID(cls, "getPackage", "(Ljava/lang/String;)Ljava/lang/Package;");
        mids$[mid_setSigners_34aa77b4] = env->getMethodID(cls, "setSigners", "(Ljava/lang/Class;[Ljava/lang/Object;)V");
        mids$[mid_findClass_7d663d97] = env->getMethodID(cls, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
        mids$[mid_defineClass_43666462] = env->getMethodID(cls, "defineClass", "(Ljava/lang/String;[BIILjava/security/ProtectionDomain;)Ljava/lang/Class;");
        mids$[mid_defineClass_deb30b89] = env->getMethodID(cls, "defineClass", "(Ljava/lang/String;Ljava/nio/ByteBuffer;Ljava/security/ProtectionDomain;)Ljava/lang/Class;");
        mids$[mid_defineClass_fd7e66de] = env->getMethodID(cls, "defineClass", "(Ljava/lang/String;[BII)Ljava/lang/Class;");
        mids$[mid_defineClass_2476a918] = env->getMethodID(cls, "defineClass", "([BII)Ljava/lang/Class;");
        mids$[mid_resolveClass_a5deaff4] = env->getMethodID(cls, "resolveClass", "(Ljava/lang/Class;)V");
        mids$[mid_findSystemClass_7d663d97] = env->getMethodID(cls, "findSystemClass", "(Ljava/lang/String;)Ljava/lang/Class;");
        mids$[mid_findLoadedClass_7d663d97] = env->getMethodID(cls, "findLoadedClass", "(Ljava/lang/String;)Ljava/lang/Class;");
        mids$[mid_findResource_77de5daa] = env->getMethodID(cls, "findResource", "(Ljava/lang/String;)Ljava/net/URL;");
        mids$[mid_findResources_1aac6a8a] = env->getMethodID(cls, "findResources", "(Ljava/lang/String;)Ljava/util/Enumeration;");
        mids$[mid_definePackage_ebf4cbfe] = env->getMethodID(cls, "definePackage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/net/URL;)Ljava/lang/Package;");
        mids$[mid_getPackages_c03e7c17] = env->getMethodID(cls, "getPackages", "()[Ljava/lang/Package;");
        mids$[mid_findLibrary_97a5258f] = env->getMethodID(cls, "findLibrary", "(Ljava/lang/String;)Ljava/lang/String;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    void ClassLoader::clearAssertionStatus() const
    {
      env->callVoidMethod(this$, mids$[mid_clearAssertionStatus_54c6a166]);
    }

    ClassLoader ClassLoader::getParent() const
    {
      return ClassLoader(env->callObjectMethod(this$, mids$[mid_getParent_8d2f11fc]));
    }

    ClassLoader ClassLoader::getSystemClassLoader()
    {
      jclass cls = env->getClass(initializeClass);
      return ClassLoader(env->callStaticObjectMethod(cls, mids$[mid_getSystemClassLoader_8d2f11fc]));
    }

    ::java::lang::Class ClassLoader::loadClass(const ::java::lang::String & a0) const
    {
      return ::java::lang::Class(env->callObjectMethod(this$, mids$[mid_loadClass_7d663d97], a0.this$));
    }

    void ClassLoader::setClassAssertionStatus(const ::java::lang::String & a0, jboolean a1) const
    {
      env->callVoidMethod(this$, mids$[mid_setClassAssertionStatus_f3691645], a0.this$, a1);
    }

    void ClassLoader::setDefaultAssertionStatus(jboolean a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setDefaultAssertionStatus_bb0c767f], a0);
    }

    void ClassLoader::setPackageAssertionStatus(const ::java::lang::String & a0, jboolean a1) const
    {
      env->callVoidMethod(this$, mids$[mid_setPackageAssertionStatus_f3691645], a0.this$, a1);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_ClassLoader_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_ClassLoader_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_ClassLoader_clearAssertionStatus(t_ClassLoader *self);
    static PyObject *t_ClassLoader_getParent(t_ClassLoader *self);
    static PyObject *t_ClassLoader_getSystemClassLoader(PyTypeObject *type);
    static PyObject *t_ClassLoader_loadClass(t_ClassLoader *self, PyObject *arg);
    static PyObject *t_ClassLoader_setClassAssertionStatus(t_ClassLoader *self, PyObject *args);
    static PyObject *t_ClassLoader_setDefaultAssertionStatus(t_ClassLoader *self, PyObject *arg);
    static PyObject *t_ClassLoader_setPackageAssertionStatus(t_ClassLoader *self, PyObject *args);
    static int t_ClassLoader_set__defaultAssertionStatus(t_ClassLoader *self, PyObject *arg, void *data);
    static PyObject *t_ClassLoader_get__parent(t_ClassLoader *self, void *data);
    static PyObject *t_ClassLoader_get__systemClassLoader(t_ClassLoader *self, void *data);
    static PyGetSetDef t_ClassLoader__fields_[] = {
      DECLARE_SET_FIELD(t_ClassLoader, defaultAssertionStatus),
      DECLARE_GET_FIELD(t_ClassLoader, parent),
      DECLARE_GET_FIELD(t_ClassLoader, systemClassLoader),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_ClassLoader__methods_[] = {
      DECLARE_METHOD(t_ClassLoader, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_ClassLoader, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_ClassLoader, clearAssertionStatus, METH_NOARGS),
      DECLARE_METHOD(t_ClassLoader, getParent, METH_NOARGS),
      DECLARE_METHOD(t_ClassLoader, getSystemClassLoader, METH_NOARGS | METH_CLASS),
      DECLARE_METHOD(t_ClassLoader, loadClass, METH_O),
      DECLARE_METHOD(t_ClassLoader, setClassAssertionStatus, METH_VARARGS),
      DECLARE_METHOD(t_ClassLoader, setDefaultAssertionStatus, METH_O),
      DECLARE_METHOD(t_ClassLoader, setPackageAssertionStatus, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(ClassLoader, t_ClassLoader, ::java::lang::Object, ClassLoader, abstract_init, 0, 0, t_ClassLoader__fields_, 0, 0);

    void t_ClassLoader::install(PyObject *module)
    {
      installType(&PY_TYPE(ClassLoader), module, "ClassLoader", 0);
    }

    void t_ClassLoader::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(ClassLoader).tp_dict, "class_", make_descriptor(ClassLoader::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(ClassLoader).tp_dict, "wrapfn_", make_descriptor(t_ClassLoader::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(ClassLoader).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_ClassLoader_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, ClassLoader::initializeClass, 1)))
        return NULL;
      return t_ClassLoader::wrap_Object(ClassLoader(((t_ClassLoader *) arg)->object.this$));
    }
    static PyObject *t_ClassLoader_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, ClassLoader::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_ClassLoader_clearAssertionStatus(t_ClassLoader *self)
    {
      OBJ_CALL(self->object.clearAssertionStatus());
      Py_RETURN_NONE;
    }

    static PyObject *t_ClassLoader_getParent(t_ClassLoader *self)
    {
      ClassLoader result((jobject) NULL);
      OBJ_CALL(result = self->object.getParent());
      return t_ClassLoader::wrap_Object(result);
    }

    static PyObject *t_ClassLoader_getSystemClassLoader(PyTypeObject *type)
    {
      ClassLoader result((jobject) NULL);
      OBJ_CALL(result = ::java::lang::ClassLoader::getSystemClassLoader());
      return t_ClassLoader::wrap_Object(result);
    }

    static PyObject *t_ClassLoader_loadClass(t_ClassLoader *self, PyObject *arg)
    {
      ::java::lang::String a0((jobject) NULL);
      ::java::lang::Class result((jobject) NULL);

      if (!parseArg(arg, "s", &a0))
      {
        OBJ_CALL(result = self->object.loadClass(a0));
        return ::java::lang::t_Class::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "loadClass", arg);
      return NULL;
    }

    static PyObject *t_ClassLoader_setClassAssertionStatus(t_ClassLoader *self, PyObject *args)
    {
      ::java::lang::String a0((jobject) NULL);
      jboolean a1;

      if (!parseArgs(args, "sZ", &a0, &a1))
      {
        OBJ_CALL(self->object.setClassAssertionStatus(a0, a1));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setClassAssertionStatus", args);
      return NULL;
    }

    static PyObject *t_ClassLoader_setDefaultAssertionStatus(t_ClassLoader *self, PyObject *arg)
    {
      jboolean a0;

      if (!parseArg(arg, "Z", &a0))
      {
        OBJ_CALL(self->object.setDefaultAssertionStatus(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setDefaultAssertionStatus", arg);
      return NULL;
    }

    static PyObject *t_ClassLoader_setPackageAssertionStatus(t_ClassLoader *self, PyObject *args)
    {
      ::java::lang::String a0((jobject) NULL);
      jboolean a1;

      if (!parseArgs(args, "sZ", &a0, &a1))
      {
        OBJ_CALL(self->object.setPackageAssertionStatus(a0, a1));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setPackageAssertionStatus", args);
      return NULL;
    }

    static int t_ClassLoader_set__defaultAssertionStatus(t_ClassLoader *self, PyObject *arg, void *data)
    {
      {
        jboolean value;
        if (!parseArg(arg, "Z", &value))
        {
          INT_CALL(self->object.setDefaultAssertionStatus(value));
          return 0;
        }
      }
      PyErr_SetArgsError((PyObject *) self, "defaultAssertionStatus", arg);
      return -1;
    }

    static PyObject *t_ClassLoader_get__parent(t_ClassLoader *self, void *data)
    {
      ClassLoader value((jobject) NULL);
      OBJ_CALL(value = self->object.getParent());
      return t_ClassLoader::wrap_Object(value);
    }

    static PyObject *t_ClassLoader_get__systemClassLoader(t_ClassLoader *self, void *data)
    {
      ClassLoader value((jobject) NULL);
      OBJ_CALL(value = self->object.getSystemClassLoader());
      return t_ClassLoader::wrap_Object(value);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Comparable.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *Comparable::class$ = NULL;
    jmethodID *Comparable::mids$ = NULL;
    bool Comparable::live$ = false;

    jclass Comparable::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/Comparable");

        mids$ = new jmethodID[max_mid];
        mids$[mid_compareTo_290588f1] = env->getMethodID(cls, "compareTo", "(Ljava/lang/Object;)I");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    jint Comparable::compareTo(const ::java::lang::Object & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_compareTo_290588f1], a0.this$);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_Comparable_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Comparable_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_Comparable_of_(t_Comparable *self, PyObject *args);
    static PyObject *t_Comparable_compareTo(t_Comparable *self, PyObject *arg);
    static PyObject *t_Comparable_get__parameters_(t_Comparable *self, void *data);
    static PyGetSetDef t_Comparable__fields_[] = {
      DECLARE_GET_FIELD(t_Comparable, parameters_),
      { NULL, NULL, NULL, NULL, NULL }
    };

    static PyMethodDef t_Comparable__methods_[] = {
      DECLARE_METHOD(t_Comparable, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Comparable, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_Comparable, of_, METH_VARARGS),
      DECLARE_METHOD(t_Comparable, compareTo, METH_O),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(Comparable, t_Comparable, ::java::lang::Object, Comparable, abstract_init, 0, 0, t_Comparable__fields_, 0, 0);
    PyObject *t_Comparable::wrap_Object(const Comparable& object, PyTypeObject *T)
    {
      PyObject *obj = t_Comparable::wrap_Object(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Comparable *self = (t_Comparable *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    PyObject *t_Comparable::wrap_jobject(const jobject& object, PyTypeObject *T)
    {
      PyObject *obj = t_Comparable::wrap_jobject(object);
      if (obj != NULL && obj != Py_None)
      {
        t_Comparable *self = (t_Comparable *) obj;
        self->parameters[0] = T;
      }
      return obj;
    }

    void t_Comparable::install(PyObject *module)
    {
      installType(&PY_TYPE(Comparable), module, "Comparable", 0);
    }

    void t_Comparable::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(Comparable).tp_dict, "class_", make_descriptor(Comparable::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(Comparable).tp_dict, "wrapfn_", make_descriptor(t_Comparable::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(Comparable).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_Comparable_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, Comparable::initializeClass, 1)))
        return NULL;
      return t_Comparable::wrap_Object(Comparable(((t_Comparable *) arg)->object.this$));
    }
    static PyObject *t_Comparable_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, Comparable::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_Comparable_of_(t_Comparable *self, PyObject *args)
    {
      if (!parseArg(args, "T", 1, &(self->parameters)))
        Py_RETURN_SELF;
      return PyErr_SetArgsError((PyObject *) self, "of_", args);
    }

    static PyObject *t_Comparable_compareTo(t_Comparable *self, PyObject *arg)
    {
      ::java::lang::Object a0((jobject) NULL);
      jint result;

      if (!parseArg(arg, "O", self->parameters[0], &a0))
      {
        OBJ_CALL(result = self->object.compareTo(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "compareTo", arg);
      return NULL;
    }
    static PyObject *t_Comparable_get__parameters_(t_Comparable *self, void *data)
    {
      return typeParameters(self->parameters, sizeof(self->parameters));
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/InterruptedException.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *InterruptedException::class$ = NULL;
    jmethodID *InterruptedException::mids$ = NULL;
    bool InterruptedException::live$ = false;

    jclass InterruptedException::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/InterruptedException");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    InterruptedException::InterruptedException() : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    InterruptedException::InterruptedException(const ::java::lang::String & a0) : ::java::lang::Exception(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_InterruptedException_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_InterruptedException_instance_(PyTypeObject *type, PyObject *arg);
    static int t_InterruptedException_init_(t_InterruptedException *self, PyObject *args, PyObject *kwds);

    static PyMethodDef t_InterruptedException__methods_[] = {
      DECLARE_METHOD(t_InterruptedException, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_InterruptedException, instance_, METH_O | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(InterruptedException, t_InterruptedException, ::java::lang::Exception, InterruptedException, t_InterruptedException_init_, 0, 0, 0, 0, 0);

    void t_InterruptedException::install(PyObject *module)
    {
      installType(&PY_TYPE(InterruptedException), module, "InterruptedException", 0);
    }

    void t_InterruptedException::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(InterruptedException).tp_dict, "class_", make_descriptor(InterruptedException::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(InterruptedException).tp_dict, "wrapfn_", make_descriptor(t_InterruptedException::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(InterruptedException).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_InterruptedException_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, InterruptedException::initializeClass, 1)))
        return NULL;
      return t_InterruptedException::wrap_Object(InterruptedException(((t_InterruptedException *) arg)->object.this$));
    }
    static PyObject *t_InterruptedException_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, InterruptedException::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_InterruptedException_init_(t_InterruptedException *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          InterruptedException object((jobject) NULL);

          INT_CALL(object = InterruptedException());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          InterruptedException object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = InterruptedException(a0));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/IllegalArgumentException.h"
#include "java/lang/Throwable.h"
#include "java/lang/String.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *IllegalArgumentException::class$ = NULL;
    jmethodID *IllegalArgumentException::mids$ = NULL;
    bool IllegalArgumentException::live$ = false;

    jclass IllegalArgumentException::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/IllegalArgumentException");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_init$_c5ec8ca4] = env->getMethodID(cls, "<init>", "(Ljava/lang/Throwable;)V");
        mids$[mid_init$_01646a2e] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    IllegalArgumentException::IllegalArgumentException() : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    IllegalArgumentException::IllegalArgumentException(const ::java::lang::String & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    IllegalArgumentException::IllegalArgumentException(const ::java::lang::Throwable & a0) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_c5ec8ca4, a0.this$)) {}

    IllegalArgumentException::IllegalArgumentException(const ::java::lang::String & a0, const ::java::lang::Throwable & a1) : ::java::lang::RuntimeException(env->newObject(initializeClass, &mids$, mid_init$_01646a2e, a0.this$, a1.this$)) {}
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_IllegalArgumentException_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_IllegalArgumentException_instance_(PyTypeObject *type, PyObject *arg);
    static int t_IllegalArgumentException_init_(t_IllegalArgumentException *self, PyObject *args, PyObject *kwds);

    static PyMethodDef t_IllegalArgumentException__methods_[] = {
      DECLARE_METHOD(t_IllegalArgumentException, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_IllegalArgumentException, instance_, METH_O | METH_CLASS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(IllegalArgumentException, t_IllegalArgumentException, ::java::lang::RuntimeException, IllegalArgumentException, t_IllegalArgumentException_init_, 0, 0, 0, 0, 0);

    void t_IllegalArgumentException::install(PyObject *module)
    {
      installType(&PY_TYPE(IllegalArgumentException), module, "IllegalArgumentException", 0);
    }

    void t_IllegalArgumentException::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(IllegalArgumentException).tp_dict, "class_", make_descriptor(IllegalArgumentException::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(IllegalArgumentException).tp_dict, "wrapfn_", make_descriptor(t_IllegalArgumentException::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(IllegalArgumentException).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_IllegalArgumentException_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, IllegalArgumentException::initializeClass, 1)))
        return NULL;
      return t_IllegalArgumentException::wrap_Object(IllegalArgumentException(((t_IllegalArgumentException *) arg)->object.this$));
    }
    static PyObject *t_IllegalArgumentException_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, IllegalArgumentException::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_IllegalArgumentException_init_(t_IllegalArgumentException *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          IllegalArgumentException object((jobject) NULL);

          INT_CALL(object = IllegalArgumentException());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          IllegalArgumentException object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = IllegalArgumentException(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::Throwable a0((jobject) NULL);
          IllegalArgumentException object((jobject) NULL);

          if (!parseArgs(args, "k", ::java::lang::Throwable::initializeClass, &a0))
          {
            INT_CALL(object = IllegalArgumentException(a0));
            self->object = object;
            break;
          }
        }
        goto err;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          ::java::lang::Throwable a1((jobject) NULL);
          IllegalArgumentException object((jobject) NULL);

          if (!parseArgs(args, "sk", ::java::lang::Throwable::initializeClass, &a0, &a1))
          {
            INT_CALL(object = IllegalArgumentException(a0, a1));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/StringBuilder.h"
#include "java/lang/String.h"
#include "java/lang/CharSequence.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *StringBuilder::class$ = NULL;
    jmethodID *StringBuilder::mids$ = NULL;
    bool StringBuilder::live$ = false;

    jclass StringBuilder::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/StringBuilder");

        mids$ = new jmethodID[max_mid];
        mids$[mid_init$_54c6a166] = env->getMethodID(cls, "<init>", "()V");
        mids$[mid_init$_39c7bd3c] = env->getMethodID(cls, "<init>", "(I)V");
        mids$[mid_init$_5fdc3f48] = env->getMethodID(cls, "<init>", "(Ljava/lang/String;)V");
        mids$[mid_init$_a8afc64a] = env->getMethodID(cls, "<init>", "(Ljava/lang/CharSequence;)V");
        mids$[mid_append_3c8cf749] = env->getMethodID(cls, "append", "([C)Ljava/lang/StringBuilder;");
        mids$[mid_append_75fd4e14] = env->getMethodID(cls, "append", "(F)Ljava/lang/StringBuilder;");
        mids$[mid_append_1c7ab4ee] = env->getMethodID(cls, "append", "(D)Ljava/lang/StringBuilder;");
        mids$[mid_append_b60c3de1] = env->getMethodID(cls, "append", "(Ljava/lang/Object;)Ljava/lang/StringBuilder;");
        mids$[mid_append_d9a60f20] = env->getMethodID(cls, "append", "(J)Ljava/lang/StringBuilder;");
        mids$[mid_append_0f09fb50] = env->getMethodID(cls, "append", "(Z)Ljava/lang/StringBuilder;");
        mids$[mid_append_e82ae26d] = env->getMethodID(cls, "append", "(C)Ljava/lang/StringBuilder;");
        mids$[mid_append_50083a71] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/StringBuilder;");
        mids$[mid_append_2dfc73db] = env->getMethodID(cls, "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;");
        mids$[mid_append_83777cef] = env->getMethodID(cls, "append", "(I)Ljava/lang/StringBuilder;");
        mids$[mid_append_8358d2a7] = env->getMethodID(cls, "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuilder;");
        mids$[mid_append_24d5875d] = env->getMethodID(cls, "append", "([CII)Ljava/lang/StringBuilder;");
        mids$[mid_append_2bd4722d] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
        mids$[mid_appendCodePoint_83777cef] = env->getMethodID(cls, "appendCodePoint", "(I)Ljava/lang/StringBuilder;");
        mids$[mid_delete_719db8f9] = env->getMethodID(cls, "delete", "(II)Ljava/lang/StringBuilder;");
        mids$[mid_deleteCharAt_83777cef] = env->getMethodID(cls, "deleteCharAt", "(I)Ljava/lang/StringBuilder;");
        mids$[mid_indexOf_5fdc3f57] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;)I");
        mids$[mid_indexOf_6e53ccd9] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;I)I");
        mids$[mid_insert_a08f263a] = env->getMethodID(cls, "insert", "(IF)Ljava/lang/StringBuilder;");
        mids$[mid_insert_4ed4b5eb] = env->getMethodID(cls, "insert", "(IC)Ljava/lang/StringBuilder;");
        mids$[mid_insert_16519a10] = env->getMethodID(cls, "insert", "(ID)Ljava/lang/StringBuilder;");
        mids$[mid_insert_012dcedd] = env->getMethodID(cls, "insert", "(ILjava/lang/String;)Ljava/lang/StringBuilder;");
        mids$[mid_insert_af7946e6] = env->getMethodID(cls, "insert", "(IJ)Ljava/lang/StringBuilder;");
        mids$[mid_insert_223b06cf] = env->getMethodID(cls, "insert", "(I[C)Ljava/lang/StringBuilder;");
        mids$[mid_insert_de03d343] = env->getMethodID(cls, "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuilder;");
        mids$[mid_insert_f2b36ed3] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;)Ljava/lang/StringBuilder;");
        mids$[mid_insert_094df9d6] = env->getMethodID(cls, "insert", "(IZ)Ljava/lang/StringBuilder;");
        mids$[mid_insert_719db8f9] = env->getMethodID(cls, "insert", "(II)Ljava/lang/StringBuilder;");
        mids$[mid_insert_2824e937] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/StringBuilder;");
        mids$[mid_insert_d3b5ed83] = env->getMethodID(cls, "insert", "(I[CII)Ljava/lang/StringBuilder;");
        mids$[mid_lastIndexOf_5fdc3f57] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;)I");
        mids$[mid_lastIndexOf_6e53ccd9] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;I)I");
        mids$[mid_replace_3740c5ff] = env->getMethodID(cls, "replace", "(IILjava/lang/String;)Ljava/lang/StringBuilder;");
        mids$[mid_reverse_a1025355] = env->getMethodID(cls, "reverse", "()Ljava/lang/StringBuilder;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    StringBuilder::StringBuilder() : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_54c6a166)) {}

    StringBuilder::StringBuilder(jint a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_39c7bd3c, a0)) {}

    StringBuilder::StringBuilder(const ::java::lang::String & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_5fdc3f48, a0.this$)) {}

    StringBuilder::StringBuilder(const ::java::lang::CharSequence & a0) : ::java::lang::AbstractStringBuilder(env->newObject(initializeClass, &mids$, mid_init$_a8afc64a, a0.this$)) {}

    StringBuilder StringBuilder::append(const JArray< jchar > & a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_3c8cf749], a0.this$));
    }

    StringBuilder StringBuilder::append(jfloat a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_75fd4e14], a0));
    }

    StringBuilder StringBuilder::append(jdouble a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_1c7ab4ee], a0));
    }

    StringBuilder StringBuilder::append(const ::java::lang::Object & a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_b60c3de1], a0.this$));
    }

    StringBuilder StringBuilder::append(jlong a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_d9a60f20], a0));
    }

    StringBuilder StringBuilder::append(jboolean a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_0f09fb50], a0));
    }

    StringBuilder StringBuilder::append(jchar a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_e82ae26d], a0));
    }

    StringBuilder StringBuilder::append(const ::java::lang::CharSequence & a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_50083a71], a0.this$));
    }

    StringBuilder StringBuilder::append(const ::java::lang::String & a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_2dfc73db], a0.this$));
    }

    StringBuilder StringBuilder::append(jint a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_83777cef], a0));
    }

    StringBuilder StringBuilder::append(const ::java::lang::StringBuffer & a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_8358d2a7], a0.this$));
    }

    StringBuilder StringBuilder::append(const JArray< jchar > & a0, jint a1, jint a2) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_24d5875d], a0.this$, a1, a2));
    }

    StringBuilder StringBuilder::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_append_2bd4722d], a0.this$, a1, a2));
    }

    StringBuilder StringBuilder::appendCodePoint(jint a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_appendCodePoint_83777cef], a0));
    }

    StringBuilder StringBuilder::delete$(jint a0, jint a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_delete_719db8f9], a0, a1));
    }

    StringBuilder StringBuilder::deleteCharAt(jint a0) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_deleteCharAt_83777cef], a0));
    }

    jint StringBuilder::indexOf(const ::java::lang::String & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_indexOf_5fdc3f57], a0.this$);
    }

    jint StringBuilder::indexOf(const ::java::lang::String & a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_indexOf_6e53ccd9], a0.this$, a1);
    }

    StringBuilder StringBuilder::insert(jint a0, jfloat a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_a08f263a], a0, a1));
    }

    StringBuilder StringBuilder::insert(jint a0, jchar a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_4ed4b5eb], a0, a1));
    }

    StringBuilder StringBuilder::insert(jint a0, jdouble a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_16519a10], a0, a1));
    }

    StringBuilder StringBuilder::insert(jint a0, const ::java::lang::String & a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_012dcedd], a0, a1.this$));
    }

    StringBuilder StringBuilder::insert(jint a0, jlong a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_af7946e6], a0, a1));
    }

    StringBuilder StringBuilder::insert(jint a0, const JArray< jchar > & a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_223b06cf], a0, a1.this$));
    }

    StringBuilder StringBuilder::insert(jint a0, const ::java::lang::Object & a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_de03d343], a0, a1.this$));
    }

    StringBuilder StringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_f2b36ed3], a0, a1.this$));
    }

    StringBuilder StringBuilder::insert(jint a0, jboolean a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_094df9d6], a0, a1));
    }

    StringBuilder StringBuilder::insert(jint a0, jint a1) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_719db8f9], a0, a1));
    }

    StringBuilder StringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1, jint a2, jint a3) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_2824e937], a0, a1.this$, a2, a3));
    }

    StringBuilder StringBuilder::insert(jint a0, const JArray< jchar > & a1, jint a2, jint a3) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_insert_d3b5ed83], a0, a1.this$, a2, a3));
    }

    jint StringBuilder::lastIndexOf(const ::java::lang::String & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_lastIndexOf_5fdc3f57], a0.this$);
    }

    jint StringBuilder::lastIndexOf(const ::java::lang::String & a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_lastIndexOf_6e53ccd9], a0.this$, a1);
    }

    StringBuilder StringBuilder::replace(jint a0, jint a1, const ::java::lang::String & a2) const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_replace_3740c5ff], a0, a1, a2.this$));
    }

    StringBuilder StringBuilder::reverse() const
    {
      return StringBuilder(env->callObjectMethod(this$, mids$[mid_reverse_a1025355]));
    }

    ::java::lang::String StringBuilder::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_StringBuilder_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_StringBuilder_instance_(PyTypeObject *type, PyObject *arg);
    static int t_StringBuilder_init_(t_StringBuilder *self, PyObject *args, PyObject *kwds);
    static PyObject *t_StringBuilder_append(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_appendCodePoint(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_delete(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_deleteCharAt(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_indexOf(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_insert(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_lastIndexOf(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_replace(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_reverse(t_StringBuilder *self, PyObject *args);
    static PyObject *t_StringBuilder_toString(t_StringBuilder *self, PyObject *args);

    static PyMethodDef t_StringBuilder__methods_[] = {
      DECLARE_METHOD(t_StringBuilder, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StringBuilder, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_StringBuilder, append, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, appendCodePoint, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, delete, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, deleteCharAt, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, indexOf, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, insert, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, lastIndexOf, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, replace, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, reverse, METH_VARARGS),
      DECLARE_METHOD(t_StringBuilder, toString, METH_VARARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(StringBuilder, t_StringBuilder, ::java::lang::AbstractStringBuilder, StringBuilder, t_StringBuilder_init_, 0, 0, 0, 0, 0);

    void t_StringBuilder::install(PyObject *module)
    {
      installType(&PY_TYPE(StringBuilder), module, "StringBuilder", 0);
    }

    void t_StringBuilder::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(StringBuilder).tp_dict, "class_", make_descriptor(StringBuilder::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(StringBuilder).tp_dict, "wrapfn_", make_descriptor(t_StringBuilder::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(StringBuilder).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_StringBuilder_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, StringBuilder::initializeClass, 1)))
        return NULL;
      return t_StringBuilder::wrap_Object(StringBuilder(((t_StringBuilder *) arg)->object.this$));
    }
    static PyObject *t_StringBuilder_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, StringBuilder::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static int t_StringBuilder_init_(t_StringBuilder *self, PyObject *args, PyObject *kwds)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 0:
        {
          StringBuilder object((jobject) NULL);

          INT_CALL(object = StringBuilder());
          self->object = object;
          break;
        }
        goto err;
       case 1:
        {
          jint a0;
          StringBuilder object((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            INT_CALL(object = StringBuilder(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          StringBuilder object((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            INT_CALL(object = StringBuilder(a0));
            self->object = object;
            break;
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          StringBuilder object((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            INT_CALL(object = StringBuilder(a0));
            self->object = object;
            break;
          }
        }
       default:
       err:
        PyErr_SetArgsError((PyObject *) self, "__init__", args);
        return -1;
      }

      return 0;
    }

    static PyObject *t_StringBuilder_append(t_StringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          JArray< jchar > a0((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "[C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jfloat a0;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "F", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jdouble a0;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "D", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::Object a0((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "o", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jlong a0;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "J", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jboolean a0;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "Z", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jchar a0;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::StringBuffer a0((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "k", ::java::lang::StringBuffer::initializeClass, &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        break;
       case 3:
        {
          JArray< jchar > a0((jobject) NULL);
          jint a1;
          jint a2;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "[CII", &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          jint a1;
          jint a2;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_StringBuilder::wrap_Object(result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "append", args, 2);
    }

    static PyObject *t_StringBuilder_appendCodePoint(t_StringBuilder *self, PyObject *args)
    {
      jint a0;
      StringBuilder result((jobject) NULL);

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(result = self->object.appendCodePoint(a0));
        return t_StringBuilder::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "appendCodePoint", args, 2);
    }

    static PyObject *t_StringBuilder_delete(t_StringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      StringBuilder result((jobject) NULL);

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.delete$(a0, a1));
        return t_StringBuilder::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "delete", args, 2);
    }

    static PyObject *t_StringBuilder_deleteCharAt(t_StringBuilder *self, PyObject *args)
    {
      jint a0;
      StringBuilder result((jobject) NULL);

      if (!parseArgs(args, "I", &a0))
      {
        OBJ_CALL(result = self->object.deleteCharAt(a0));
        return t_StringBuilder::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "deleteCharAt", args, 2);
    }

    static PyObject *t_StringBuilder_indexOf(t_StringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jint result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.indexOf(a0));
            return PyInt_FromLong((long) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = self->object.indexOf(a0, a1));
            return PyInt_FromLong((long) result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "indexOf", args, 2);
    }

    static PyObject *t_StringBuilder_insert(t_StringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 2:
        {
          jint a0;
          jfloat a1;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IF", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jchar a1;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IC", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jdouble a1;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "ID", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::String a1((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "Is", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jlong a1;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IJ", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          JArray< jchar > a1((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "I[C", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::Object a1((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "Io", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::CharSequence a1((jobject) NULL);
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IO", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jboolean a1;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IZ", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jint a1;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "II", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        break;
       case 4:
        {
          jint a0;
          ::java::lang::CharSequence a1((jobject) NULL);
          jint a2;
          jint a3;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IOII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2, &a3))
          {
            OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
            return t_StringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          JArray< jchar > a1((jobject) NULL);
          jint a2;
          jint a3;
          StringBuilder result((jobject) NULL);

          if (!parseArgs(args, "I[CII", &a0, &a1, &a2, &a3))
          {
            OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
            return t_StringBuilder::wrap_Object(result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "insert", args, 2);
    }

    static PyObject *t_StringBuilder_lastIndexOf(t_StringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jint result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.lastIndexOf(a0));
            return PyInt_FromLong((long) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
            return PyInt_FromLong((long) result);
          }
        }
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "lastIndexOf", args, 2);
    }

    static PyObject *t_StringBuilder_replace(t_StringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      ::java::lang::String a2((jobject) NULL);
      StringBuilder result((jobject) NULL);

      if (!parseArgs(args, "IIs", &a0, &a1, &a2))
      {
        OBJ_CALL(result = self->object.replace(a0, a1, a2));
        return t_StringBuilder::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "replace", args, 2);
    }

    static PyObject *t_StringBuilder_reverse(t_StringBuilder *self, PyObject *args)
    {
      StringBuilder result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.reverse());
        return t_StringBuilder::wrap_Object(result);
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "reverse", args, 2);
    }

    static PyObject *t_StringBuilder_toString(t_StringBuilder *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(StringBuilder), (PyObject *) self, "toString", args, 2);
    }
  }
}
#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/AbstractStringBuilder.h"
#include "java/lang/String.h"
#include "java/lang/Appendable.h"
#include "java/lang/CharSequence.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/Class.h"
#include "JArray.h"

namespace java {
  namespace lang {

    ::java::lang::Class *AbstractStringBuilder::class$ = NULL;
    jmethodID *AbstractStringBuilder::mids$ = NULL;
    bool AbstractStringBuilder::live$ = false;

    jclass AbstractStringBuilder::initializeClass(bool getOnly)
    {
      if (getOnly)
        return (jclass) (live$ ? class$->this$ : NULL);
      if (class$ == NULL)
      {
        jclass cls = (jclass) env->findClass("java/lang/AbstractStringBuilder");

        mids$ = new jmethodID[max_mid];
        mids$[mid_append_7c173d47] = env->getMethodID(cls, "append", "([C)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_a2ed0092] = env->getMethodID(cls, "append", "(F)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_5e58b04c] = env->getMethodID(cls, "append", "(D)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_db02ec8f] = env->getMethodID(cls, "append", "(Ljava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_4d0b6cce] = env->getMethodID(cls, "append", "(J)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_9dc99a1e] = env->getMethodID(cls, "append", "(Z)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_a6b3f18b] = env->getMethodID(cls, "append", "(C)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_97dd5503] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_0f3b1ca9] = env->getMethodID(cls, "append", "(Ljava/lang/String;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_2814c015] = env->getMethodID(cls, "append", "(I)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_5337ed99] = env->getMethodID(cls, "append", "(Ljava/lang/StringBuffer;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_c2cdc21f] = env->getMethodID(cls, "append", "([CII)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_append_7e485efb] = env->getMethodID(cls, "append", "(Ljava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_appendCodePoint_2814c015] = env->getMethodID(cls, "appendCodePoint", "(I)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_capacity_54c6a179] = env->getMethodID(cls, "capacity", "()I");
        mids$[mid_charAt_39c7bd29] = env->getMethodID(cls, "charAt", "(I)C");
        mids$[mid_codePointAt_39c7bd23] = env->getMethodID(cls, "codePointAt", "(I)I");
        mids$[mid_codePointBefore_39c7bd23] = env->getMethodID(cls, "codePointBefore", "(I)I");
        mids$[mid_codePointCount_d8d154b9] = env->getMethodID(cls, "codePointCount", "(II)I");
        mids$[mid_delete_2b8ead17] = env->getMethodID(cls, "delete", "(II)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_deleteCharAt_2814c015] = env->getMethodID(cls, "deleteCharAt", "(I)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_ensureCapacity_39c7bd3c] = env->getMethodID(cls, "ensureCapacity", "(I)V");
        mids$[mid_getChars_06518f84] = env->getMethodID(cls, "getChars", "(II[CI)V");
        mids$[mid_indexOf_5fdc3f57] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;)I");
        mids$[mid_indexOf_6e53ccd9] = env->getMethodID(cls, "indexOf", "(Ljava/lang/String;I)I");
        mids$[mid_insert_6089bc60] = env->getMethodID(cls, "insert", "(IF)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_af3c3de9] = env->getMethodID(cls, "insert", "(I[C)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_62ac5207] = env->getMethodID(cls, "insert", "(ILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_2b8ead17] = env->getMethodID(cls, "insert", "(II)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_d1cc213e] = env->getMethodID(cls, "insert", "(ID)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_5236bc0d] = env->getMethodID(cls, "insert", "(ILjava/lang/Object;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_8567b539] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_06d282ac] = env->getMethodID(cls, "insert", "(IZ)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_063a9eb9] = env->getMethodID(cls, "insert", "(IC)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_9beca11c] = env->getMethodID(cls, "insert", "(IJ)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_78ebdb01] = env->getMethodID(cls, "insert", "(ILjava/lang/CharSequence;II)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_insert_24aafa89] = env->getMethodID(cls, "insert", "(I[CII)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_lastIndexOf_5fdc3f57] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;)I");
        mids$[mid_lastIndexOf_6e53ccd9] = env->getMethodID(cls, "lastIndexOf", "(Ljava/lang/String;I)I");
        mids$[mid_length_54c6a179] = env->getMethodID(cls, "length", "()I");
        mids$[mid_offsetByCodePoints_d8d154b9] = env->getMethodID(cls, "offsetByCodePoints", "(II)I");
        mids$[mid_replace_349953a9] = env->getMethodID(cls, "replace", "(IILjava/lang/String;)Ljava/lang/AbstractStringBuilder;");
        mids$[mid_reverse_570c12f7] = env->getMethodID(cls, "reverse", "()Ljava/lang/AbstractStringBuilder;");
        mids$[mid_setCharAt_83eec158] = env->getMethodID(cls, "setCharAt", "(IC)V");
        mids$[mid_setLength_39c7bd3c] = env->getMethodID(cls, "setLength", "(I)V");
        mids$[mid_subSequence_f88dfd57] = env->getMethodID(cls, "subSequence", "(II)Ljava/lang/CharSequence;");
        mids$[mid_substring_141401b3] = env->getMethodID(cls, "substring", "(I)Ljava/lang/String;");
        mids$[mid_substring_f9118fe5] = env->getMethodID(cls, "substring", "(II)Ljava/lang/String;");
        mids$[mid_toString_14c7b5c5] = env->getMethodID(cls, "toString", "()Ljava/lang/String;");
        mids$[mid_trimToSize_54c6a166] = env->getMethodID(cls, "trimToSize", "()V");

        class$ = (::java::lang::Class *) new JObject(cls);
        live$ = true;
      }
      return (jclass) class$->this$;
    }

    AbstractStringBuilder AbstractStringBuilder::append(const JArray< jchar > & a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_7c173d47], a0.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::append(jfloat a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_a2ed0092], a0));
    }

    AbstractStringBuilder AbstractStringBuilder::append(jdouble a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_5e58b04c], a0));
    }

    AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::Object & a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_db02ec8f], a0.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::append(jlong a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_4d0b6cce], a0));
    }

    AbstractStringBuilder AbstractStringBuilder::append(jboolean a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_9dc99a1e], a0));
    }

    AbstractStringBuilder AbstractStringBuilder::append(jchar a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_a6b3f18b], a0));
    }

    AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::CharSequence & a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_97dd5503], a0.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::String & a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_0f3b1ca9], a0.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::append(jint a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_2814c015], a0));
    }

    AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::StringBuffer & a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_5337ed99], a0.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::append(const JArray< jchar > & a0, jint a1, jint a2) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_c2cdc21f], a0.this$, a1, a2));
    }

    AbstractStringBuilder AbstractStringBuilder::append(const ::java::lang::CharSequence & a0, jint a1, jint a2) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_append_7e485efb], a0.this$, a1, a2));
    }

    AbstractStringBuilder AbstractStringBuilder::appendCodePoint(jint a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_appendCodePoint_2814c015], a0));
    }

    jint AbstractStringBuilder::capacity() const
    {
      return env->callIntMethod(this$, mids$[mid_capacity_54c6a179]);
    }

    jchar AbstractStringBuilder::charAt(jint a0) const
    {
      return env->callCharMethod(this$, mids$[mid_charAt_39c7bd29], a0);
    }

    jint AbstractStringBuilder::codePointAt(jint a0) const
    {
      return env->callIntMethod(this$, mids$[mid_codePointAt_39c7bd23], a0);
    }

    jint AbstractStringBuilder::codePointBefore(jint a0) const
    {
      return env->callIntMethod(this$, mids$[mid_codePointBefore_39c7bd23], a0);
    }

    jint AbstractStringBuilder::codePointCount(jint a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_codePointCount_d8d154b9], a0, a1);
    }

    AbstractStringBuilder AbstractStringBuilder::delete$(jint a0, jint a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_delete_2b8ead17], a0, a1));
    }

    AbstractStringBuilder AbstractStringBuilder::deleteCharAt(jint a0) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_deleteCharAt_2814c015], a0));
    }

    void AbstractStringBuilder::ensureCapacity(jint a0) const
    {
      env->callVoidMethod(this$, mids$[mid_ensureCapacity_39c7bd3c], a0);
    }

    void AbstractStringBuilder::getChars(jint a0, jint a1, const JArray< jchar > & a2, jint a3) const
    {
      env->callVoidMethod(this$, mids$[mid_getChars_06518f84], a0, a1, a2.this$, a3);
    }

    jint AbstractStringBuilder::indexOf(const ::java::lang::String & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_indexOf_5fdc3f57], a0.this$);
    }

    jint AbstractStringBuilder::indexOf(const ::java::lang::String & a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_indexOf_6e53ccd9], a0.this$, a1);
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jfloat a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_6089bc60], a0, a1));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const JArray< jchar > & a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_af3c3de9], a0, a1.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::String & a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_62ac5207], a0, a1.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jint a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_2b8ead17], a0, a1));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jdouble a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_d1cc213e], a0, a1));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::Object & a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_5236bc0d], a0, a1.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_8567b539], a0, a1.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jboolean a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_06d282ac], a0, a1));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jchar a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_063a9eb9], a0, a1));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, jlong a1) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_9beca11c], a0, a1));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const ::java::lang::CharSequence & a1, jint a2, jint a3) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_78ebdb01], a0, a1.this$, a2, a3));
    }

    AbstractStringBuilder AbstractStringBuilder::insert(jint a0, const JArray< jchar > & a1, jint a2, jint a3) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_insert_24aafa89], a0, a1.this$, a2, a3));
    }

    jint AbstractStringBuilder::lastIndexOf(const ::java::lang::String & a0) const
    {
      return env->callIntMethod(this$, mids$[mid_lastIndexOf_5fdc3f57], a0.this$);
    }

    jint AbstractStringBuilder::lastIndexOf(const ::java::lang::String & a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_lastIndexOf_6e53ccd9], a0.this$, a1);
    }

    jint AbstractStringBuilder::length() const
    {
      return env->callIntMethod(this$, mids$[mid_length_54c6a179]);
    }

    jint AbstractStringBuilder::offsetByCodePoints(jint a0, jint a1) const
    {
      return env->callIntMethod(this$, mids$[mid_offsetByCodePoints_d8d154b9], a0, a1);
    }

    AbstractStringBuilder AbstractStringBuilder::replace(jint a0, jint a1, const ::java::lang::String & a2) const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_replace_349953a9], a0, a1, a2.this$));
    }

    AbstractStringBuilder AbstractStringBuilder::reverse() const
    {
      return AbstractStringBuilder(env->callObjectMethod(this$, mids$[mid_reverse_570c12f7]));
    }

    void AbstractStringBuilder::setCharAt(jint a0, jchar a1) const
    {
      env->callVoidMethod(this$, mids$[mid_setCharAt_83eec158], a0, a1);
    }

    void AbstractStringBuilder::setLength(jint a0) const
    {
      env->callVoidMethod(this$, mids$[mid_setLength_39c7bd3c], a0);
    }

    ::java::lang::CharSequence AbstractStringBuilder::subSequence(jint a0, jint a1) const
    {
      return ::java::lang::CharSequence(env->callObjectMethod(this$, mids$[mid_subSequence_f88dfd57], a0, a1));
    }

    ::java::lang::String AbstractStringBuilder::substring(jint a0) const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_141401b3], a0));
    }

    ::java::lang::String AbstractStringBuilder::substring(jint a0, jint a1) const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_substring_f9118fe5], a0, a1));
    }

    ::java::lang::String AbstractStringBuilder::toString() const
    {
      return ::java::lang::String(env->callObjectMethod(this$, mids$[mid_toString_14c7b5c5]));
    }

    void AbstractStringBuilder::trimToSize() const
    {
      env->callVoidMethod(this$, mids$[mid_trimToSize_54c6a166]);
    }
  }
}

#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
  namespace lang {
    static PyObject *t_AbstractStringBuilder_cast_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_instance_(PyTypeObject *type, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_append(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_appendCodePoint(t_AbstractStringBuilder *self, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_capacity(t_AbstractStringBuilder *self);
    static PyObject *t_AbstractStringBuilder_charAt(t_AbstractStringBuilder *self, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_codePointAt(t_AbstractStringBuilder *self, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_codePointBefore(t_AbstractStringBuilder *self, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_codePointCount(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_delete(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_deleteCharAt(t_AbstractStringBuilder *self, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_ensureCapacity(t_AbstractStringBuilder *self, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_getChars(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_indexOf(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_insert(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_lastIndexOf(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_length(t_AbstractStringBuilder *self);
    static PyObject *t_AbstractStringBuilder_offsetByCodePoints(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_replace(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_reverse(t_AbstractStringBuilder *self);
    static PyObject *t_AbstractStringBuilder_setCharAt(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_setLength(t_AbstractStringBuilder *self, PyObject *arg);
    static PyObject *t_AbstractStringBuilder_subSequence(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_substring(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_toString(t_AbstractStringBuilder *self, PyObject *args);
    static PyObject *t_AbstractStringBuilder_trimToSize(t_AbstractStringBuilder *self);

    static PyMethodDef t_AbstractStringBuilder__methods_[] = {
      DECLARE_METHOD(t_AbstractStringBuilder, cast_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_AbstractStringBuilder, instance_, METH_O | METH_CLASS),
      DECLARE_METHOD(t_AbstractStringBuilder, append, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, appendCodePoint, METH_O),
      DECLARE_METHOD(t_AbstractStringBuilder, capacity, METH_NOARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, charAt, METH_O),
      DECLARE_METHOD(t_AbstractStringBuilder, codePointAt, METH_O),
      DECLARE_METHOD(t_AbstractStringBuilder, codePointBefore, METH_O),
      DECLARE_METHOD(t_AbstractStringBuilder, codePointCount, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, delete, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, deleteCharAt, METH_O),
      DECLARE_METHOD(t_AbstractStringBuilder, ensureCapacity, METH_O),
      DECLARE_METHOD(t_AbstractStringBuilder, getChars, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, indexOf, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, insert, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, lastIndexOf, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, length, METH_NOARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, offsetByCodePoints, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, replace, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, reverse, METH_NOARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, setCharAt, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, setLength, METH_O),
      DECLARE_METHOD(t_AbstractStringBuilder, subSequence, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, substring, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, toString, METH_VARARGS),
      DECLARE_METHOD(t_AbstractStringBuilder, trimToSize, METH_NOARGS),
      { NULL, NULL, 0, NULL }
    };

    DECLARE_TYPE(AbstractStringBuilder, t_AbstractStringBuilder, ::java::lang::Object, AbstractStringBuilder, abstract_init, 0, 0, 0, 0, 0);

    void t_AbstractStringBuilder::install(PyObject *module)
    {
      installType(&PY_TYPE(AbstractStringBuilder), module, "AbstractStringBuilder", 0);
    }

    void t_AbstractStringBuilder::initialize(PyObject *module)
    {
      PyDict_SetItemString(PY_TYPE(AbstractStringBuilder).tp_dict, "class_", make_descriptor(AbstractStringBuilder::initializeClass, 1));
      PyDict_SetItemString(PY_TYPE(AbstractStringBuilder).tp_dict, "wrapfn_", make_descriptor(t_AbstractStringBuilder::wrap_jobject));
      PyDict_SetItemString(PY_TYPE(AbstractStringBuilder).tp_dict, "boxfn_", make_descriptor(boxObject));
    }

    static PyObject *t_AbstractStringBuilder_cast_(PyTypeObject *type, PyObject *arg)
    {
      if (!(arg = castCheck(arg, AbstractStringBuilder::initializeClass, 1)))
        return NULL;
      return t_AbstractStringBuilder::wrap_Object(AbstractStringBuilder(((t_AbstractStringBuilder *) arg)->object.this$));
    }
    static PyObject *t_AbstractStringBuilder_instance_(PyTypeObject *type, PyObject *arg)
    {
      if (!castCheck(arg, AbstractStringBuilder::initializeClass, 0))
        Py_RETURN_FALSE;
      Py_RETURN_TRUE;
    }

    static PyObject *t_AbstractStringBuilder_append(t_AbstractStringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          JArray< jchar > a0((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "[C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jfloat a0;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "F", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jdouble a0;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "D", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::Object a0((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "o", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jlong a0;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "J", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jboolean a0;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "Z", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jchar a0;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "C", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "O", &::java::lang::PY_TYPE(CharSequence), &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::String a0((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::StringBuffer a0((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "k", ::java::lang::StringBuffer::initializeClass, &a0))
          {
            OBJ_CALL(result = self->object.append(a0));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        break;
       case 3:
        {
          JArray< jchar > a0((jobject) NULL);
          jint a1;
          jint a2;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "[CII", &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          ::java::lang::CharSequence a0((jobject) NULL);
          jint a1;
          jint a2;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "OII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2))
          {
            OBJ_CALL(result = self->object.append(a0, a1, a2));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "append", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_appendCodePoint(t_AbstractStringBuilder *self, PyObject *arg)
    {
      jint a0;
      AbstractStringBuilder result((jobject) NULL);

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = self->object.appendCodePoint(a0));
        return t_AbstractStringBuilder::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "appendCodePoint", arg);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_capacity(t_AbstractStringBuilder *self)
    {
      jint result;
      OBJ_CALL(result = self->object.capacity());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_AbstractStringBuilder_charAt(t_AbstractStringBuilder *self, PyObject *arg)
    {
      jint a0;
      jchar result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = self->object.charAt(a0));
        return PyUnicode_FromUnicode((Py_UNICODE *) &result, 1);
      }

      PyErr_SetArgsError((PyObject *) self, "charAt", arg);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_codePointAt(t_AbstractStringBuilder *self, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = self->object.codePointAt(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "codePointAt", arg);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_codePointBefore(t_AbstractStringBuilder *self, PyObject *arg)
    {
      jint a0;
      jint result;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = self->object.codePointBefore(a0));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "codePointBefore", arg);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_codePointCount(t_AbstractStringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      jint result;

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.codePointCount(a0, a1));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "codePointCount", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_delete(t_AbstractStringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      AbstractStringBuilder result((jobject) NULL);

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.delete$(a0, a1));
        return t_AbstractStringBuilder::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "delete", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_deleteCharAt(t_AbstractStringBuilder *self, PyObject *arg)
    {
      jint a0;
      AbstractStringBuilder result((jobject) NULL);

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(result = self->object.deleteCharAt(a0));
        return t_AbstractStringBuilder::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "deleteCharAt", arg);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_ensureCapacity(t_AbstractStringBuilder *self, PyObject *arg)
    {
      jint a0;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(self->object.ensureCapacity(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "ensureCapacity", arg);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_getChars(t_AbstractStringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      JArray< jchar > a2((jobject) NULL);
      jint a3;

      if (!parseArgs(args, "II[CI", &a0, &a1, &a2, &a3))
      {
        OBJ_CALL(self->object.getChars(a0, a1, a2, a3));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "getChars", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_indexOf(t_AbstractStringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jint result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.indexOf(a0));
            return PyInt_FromLong((long) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = self->object.indexOf(a0, a1));
            return PyInt_FromLong((long) result);
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "indexOf", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_insert(t_AbstractStringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 2:
        {
          jint a0;
          jfloat a1;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IF", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          JArray< jchar > a1((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "I[C", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::String a1((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "Is", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jint a1;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "II", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jdouble a1;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "ID", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::Object a1((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "Io", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          ::java::lang::CharSequence a1((jobject) NULL);
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IO", &::java::lang::PY_TYPE(CharSequence), &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jboolean a1;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IZ", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jchar a1;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IC", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          jlong a1;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IJ", &a0, &a1))
          {
            OBJ_CALL(result = self->object.insert(a0, a1));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        break;
       case 4:
        {
          jint a0;
          ::java::lang::CharSequence a1((jobject) NULL);
          jint a2;
          jint a3;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "IOII", &::java::lang::PY_TYPE(CharSequence), &a0, &a1, &a2, &a3))
          {
            OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
        {
          jint a0;
          JArray< jchar > a1((jobject) NULL);
          jint a2;
          jint a3;
          AbstractStringBuilder result((jobject) NULL);

          if (!parseArgs(args, "I[CII", &a0, &a1, &a2, &a3))
          {
            OBJ_CALL(result = self->object.insert(a0, a1, a2, a3));
            return t_AbstractStringBuilder::wrap_Object(result);
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "insert", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_lastIndexOf(t_AbstractStringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          ::java::lang::String a0((jobject) NULL);
          jint result;

          if (!parseArgs(args, "s", &a0))
          {
            OBJ_CALL(result = self->object.lastIndexOf(a0));
            return PyInt_FromLong((long) result);
          }
        }
        break;
       case 2:
        {
          ::java::lang::String a0((jobject) NULL);
          jint a1;
          jint result;

          if (!parseArgs(args, "sI", &a0, &a1))
          {
            OBJ_CALL(result = self->object.lastIndexOf(a0, a1));
            return PyInt_FromLong((long) result);
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "lastIndexOf", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_length(t_AbstractStringBuilder *self)
    {
      jint result;
      OBJ_CALL(result = self->object.length());
      return PyInt_FromLong((long) result);
    }

    static PyObject *t_AbstractStringBuilder_offsetByCodePoints(t_AbstractStringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      jint result;

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.offsetByCodePoints(a0, a1));
        return PyInt_FromLong((long) result);
      }

      PyErr_SetArgsError((PyObject *) self, "offsetByCodePoints", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_replace(t_AbstractStringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      ::java::lang::String a2((jobject) NULL);
      AbstractStringBuilder result((jobject) NULL);

      if (!parseArgs(args, "IIs", &a0, &a1, &a2))
      {
        OBJ_CALL(result = self->object.replace(a0, a1, a2));
        return t_AbstractStringBuilder::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "replace", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_reverse(t_AbstractStringBuilder *self)
    {
      AbstractStringBuilder result((jobject) NULL);
      OBJ_CALL(result = self->object.reverse());
      return t_AbstractStringBuilder::wrap_Object(result);
    }

    static PyObject *t_AbstractStringBuilder_setCharAt(t_AbstractStringBuilder *self, PyObject *args)
    {
      jint a0;
      jchar a1;

      if (!parseArgs(args, "IC", &a0, &a1))
      {
        OBJ_CALL(self->object.setCharAt(a0, a1));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setCharAt", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_setLength(t_AbstractStringBuilder *self, PyObject *arg)
    {
      jint a0;

      if (!parseArg(arg, "I", &a0))
      {
        OBJ_CALL(self->object.setLength(a0));
        Py_RETURN_NONE;
      }

      PyErr_SetArgsError((PyObject *) self, "setLength", arg);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_subSequence(t_AbstractStringBuilder *self, PyObject *args)
    {
      jint a0;
      jint a1;
      ::java::lang::CharSequence result((jobject) NULL);

      if (!parseArgs(args, "II", &a0, &a1))
      {
        OBJ_CALL(result = self->object.subSequence(a0, a1));
        return ::java::lang::t_CharSequence::wrap_Object(result);
      }

      PyErr_SetArgsError((PyObject *) self, "subSequence", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_substring(t_AbstractStringBuilder *self, PyObject *args)
    {
      switch (PyTuple_GET_SIZE(args)) {
       case 1:
        {
          jint a0;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "I", &a0))
          {
            OBJ_CALL(result = self->object.substring(a0));
            return j2p(result);
          }
        }
        break;
       case 2:
        {
          jint a0;
          jint a1;
          ::java::lang::String result((jobject) NULL);

          if (!parseArgs(args, "II", &a0, &a1))
          {
            OBJ_CALL(result = self->object.substring(a0, a1));
            return j2p(result);
          }
        }
      }

      PyErr_SetArgsError((PyObject *) self, "substring", args);
      return NULL;
    }

    static PyObject *t_AbstractStringBuilder_toString(t_AbstractStringBuilder *self, PyObject *args)
    {
      ::java::lang::String result((jobject) NULL);

      if (!parseArgs(args, ""))
      {
        OBJ_CALL(result = self->object.toString());
        return j2p(result);
      }

      return callSuper(&PY_TYPE(AbstractStringBuilder), (PyObject *) self, "toString", args, 2);
    }

    static PyObject *t_AbstractStringBuilder_trimToSize(t_AbstractStringBuilder *self)
    {
      OBJ_CALL(self->object.trimToSize());
      Py_RETURN_NONE;
    }
  }
}
