from models.serialize.DefaultTypeExceptions import *
from models.serialize.type_base import *
from models.serialize.default_enum_type import *
from models.serialize.default_string_type import *
from models.serialize.default_serializable_type import *

def SignalType():
  return DefaultEnumType(
    "SignalType",
    {
      "TRIANGLE":0,
      "SQUARE":1,
      "SINE":2,
      "NOISE":3,
    }
  )
