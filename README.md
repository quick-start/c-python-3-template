### Template for creating a C python 3 module

To build the module (in place):

```
$ python setup.py build_ext --inplace
```

To use the module:

```
>>> import cos_module
>>> print(cos_module.cos_func(1.0))
```

