#ifndef XMLHEADER_H_INCLUDED
#define XMLHEADER_H_INCLUDED

#include "libxml/encoding.h"
#include "libxml/xmlwriter.h"
// xml
#define CLEAN(w) xmlFreeTextWriter(w)

//     Element
#define W_W_E(w, n, t) xmlTextWriterWriteElement(w, BAD_CAST n, BAD_CAST t)
#define W_S_E(w, t) xmlTextWriterStartElement(w, BAD_CAST t)
#define W_E_E(w) xmlTextWriterEndElement(w)
#define W_W_R(w, t) xmlTextWriterWriteRaw(w,BAD_CAST t)
#define W_SE_E(w, t) xmlTextWriterStartElement(w, BAD_CAST t);xmlTextWriterEndElement(w)
#define W_SWE_EAE(w,et,n,t) xmlTextWriterStartElement(w, BAD_CAST et);xmlTextWriterWriteAttribute(w, BAD_CAST n, BAD_CAST t);xmlTextWriterEndElement(w)
//     Attribute
#define W_W_A(w, n, t) xmlTextWriterWriteAttribute(w, BAD_CAST n, BAD_CAST t)

//      Document
#define W_S_D(w,s) xmlTextWriterStartDocument(writer, "1.0", "UTF-8", s)
#define W_E_D(w) xmlTextWriterEndDocument(w)
#endif // XMLHEADER_H_INCLUDED
