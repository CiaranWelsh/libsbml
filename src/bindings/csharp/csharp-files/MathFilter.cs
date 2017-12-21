using System;
using System.Runtime.InteropServices;

//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.12
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace libsbmlcs {

public class MathFilter : ElementFilter {
	private HandleRef swigCPtr;

	internal MathFilter(IntPtr cPtr, bool cMemoryOwn) : base(libsbmlPINVOKE.MathFilter_SWIGUpcast(cPtr), cMemoryOwn)
	{
		//super(libsbmlPINVOKE.MathFilterUpcast(cPtr), cMemoryOwn);
		swigCPtr = new HandleRef(this, cPtr);
	}

	internal static HandleRef getCPtr(MathFilter obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}

	internal static HandleRef getCPtrAndDisown (MathFilter obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);

		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}

		return ptr;
	}

  ~MathFilter() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_MathFilter(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }


/** */ /* libsbml-internal */ public
 MathFilter() : this(libsbmlPINVOKE.new_MathFilter(), true) {
  }


/** */ /* libsbml-internal */ public new
 bool filter(SBase element) {
    bool ret = libsbmlPINVOKE.MathFilter_filter(swigCPtr, SBase.getCPtr(element));
    return ret;
  }

}

}