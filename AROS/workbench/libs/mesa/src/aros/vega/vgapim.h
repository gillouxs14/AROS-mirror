#ifndef VGAPIM_H
#define VGAPIM_H
VGErrorCode mvgGetError ();
void mvgFlush ();
void mvgFinish ();
void mvgSetf (VGParamType type, VGfloat value);
void mvgSeti (VGParamType type, VGint value);
void mvgSetfv (VGParamType type, VGint count, const VGfloat * values);
void mvgSetiv (VGParamType type, VGint count, const VGint * values);
VGfloat mvgGetf (VGParamType type);
VGint mvgGeti (VGParamType type);
VGint mvgGetVectorSize (VGParamType type);
void mvgGetfv (VGParamType type, VGint count, VGfloat * values);
void mvgGetiv (VGParamType type, VGint count, VGint * values);
void mvgSetParameterf (VGHandle object, VGint paramType, VGfloat value);
void mvgSetParameteri (VGHandle object, VGint paramType, VGint value);
void mvgSetParameterfv (VGHandle object, VGint paramType, VGint count, const VGfloat * values);
void mvgSetParameteriv (VGHandle object, VGint paramType, VGint count, const VGint * values);
VGfloat mvgGetParameterf (VGHandle object, VGint paramType);
VGint mvgGetParameteri (VGHandle object, VGint paramType);
VGint mvgGetParameterVectorSize (VGHandle object, VGint paramType);
void mvgGetParameterfv (VGHandle object, VGint paramType, VGint count, VGfloat * values);
void mvgGetParameteriv (VGHandle object, VGint paramType, VGint count, VGint * values);
void mvgLoadIdentity ();
void mvgLoadMatrix (const VGfloat * m);
void mvgGetMatrix (VGfloat * m);
void mvgMultMatrix (const VGfloat * m);
void mvgTranslate (VGfloat tx, VGfloat ty);
void mvgScale (VGfloat sx, VGfloat sy);
void mvgShear (VGfloat shx, VGfloat shy);
void mvgRotate (VGfloat angle);
void mvgMask (VGHandle mask, VGMaskOperation operation, VGint x, VGint y, VGint width, VGint height);
void mvgRenderToMask (VGPath path, VGbitfield paintModes, VGMaskOperation operation);
VGMaskLayer mvgCreateMaskLayer (VGint width, VGint height);
void mvgDestroyMaskLayer (VGMaskLayer maskLayer);
void mvgFillMaskLayer (VGMaskLayer maskLayer, VGint x, VGint y, VGint width, VGint height, VGfloat value);
void mvgCopyMask (VGMaskLayer maskLayer, VGint dx, VGint dy, VGint sx, VGint sy, VGint width, VGint height);
void mvgClear (VGint x, VGint y, VGint width, VGint height);
VGPath mvgCreatePath (VGint pathFormat, VGPathDatatype datatype, VGfloat scale, VGfloat bias, VGint segmentCapacityHint, VGint coordCapacityHint, VGbitfield capabilities);
void mvgClearPath (VGPath path, VGbitfield capabilities);
void mvgDestroyPath (VGPath path);
void mvgRemovePathCapabilities (VGPath path, VGbitfield capabilities);
VGbitfield mvgGetPathCapabilities (VGPath path);
void mvgAppendPath (VGPath dstPath, VGPath srcPath);
void mvgAppendPathData (VGPath dstPath, VGint numSegments, const VGubyte * pathSegments, const void * pathData);
void mvgModifyPathCoords (VGPath dstPath, VGint startIndex, VGint numSegments, const void * pathData);
void mvgTransformPath (VGPath dstPath, VGPath srcPath);
VGboolean mvgInterpolatePath (VGPath dstPath, VGPath startPath, VGPath endPath, VGfloat amount);
VGfloat mvgPathLength (VGPath path, VGint startSegment, VGint numSegments);
void mvgPointAlongPath (VGPath path, VGint startSegment, VGint numSegments, VGfloat distance, VGfloat * x, VGfloat * y, VGfloat * tangentX, VGfloat * tangentY);
void mvgPathBounds (VGPath path, VGfloat * minX, VGfloat * minY, VGfloat * width, VGfloat * height);
void mvgPathTransformedBounds (VGPath path, VGfloat * minX, VGfloat * minY, VGfloat * width, VGfloat * height);
void mvgDrawPath (VGPath path, VGbitfield paintModes);
VGPaint mvgCreatePaint ();
void mvgDestroyPaint (VGPaint paint);
void mvgSetPaint (VGPaint paint, VGbitfield paintModes);
VGPaint mvgGetPaint (VGPaintMode paintMode);
void mvgSetColor (VGPaint paint, VGuint rgba);
VGuint mvgGetColor (VGPaint paint);
void mvgPaintPattern (VGPaint paint, VGImage pattern);
VGImage mvgCreateImage (VGImageFormat format, VGint width, VGint height, VGbitfield allowedQuality);
void mvgDestroyImage (VGImage image);
void mvgClearImage (VGImage image, VGint x, VGint y, VGint width, VGint height);
void mvgImageSubData (VGImage image, const void * data, VGint dataStride, VGImageFormat dataFormat, VGint x, VGint y, VGint width, VGint height);
void mvgGetImageSubData (VGImage image, void * data, VGint dataStride, VGImageFormat dataFormat, VGint x, VGint y, VGint width, VGint height);
VGImage mvgChildImage (VGImage parent, VGint x, VGint y, VGint width, VGint height);
VGImage mvgGetParent (VGImage image);
void mvgCopyImage (VGImage dst, VGint dx, VGint dy, VGImage src, VGint sx, VGint sy, VGint width, VGint height, VGboolean dither);
void mvgDrawImage (VGImage image);
void mvgSetPixels (VGint dx, VGint dy, VGImage src, VGint sx, VGint sy, VGint width, VGint height);
void mvgWritePixels (const void * data, VGint dataStride, VGImageFormat dataFormat, VGint dx, VGint dy, VGint width, VGint height);
void mvgGetPixels (VGImage dst, VGint dx, VGint dy, VGint sx, VGint sy, VGint width, VGint height);
void mvgReadPixels (void * data, VGint dataStride, VGImageFormat dataFormat, VGint sx, VGint sy, VGint width, VGint height);
void mvgCopyPixels (VGint dx, VGint dy, VGint sx, VGint sy, VGint width, VGint height);
VGFont mvgCreateFont (VGint glyphCapacityHint);
void mvgDestroyFont (VGFont font);
void mvgSetGlyphToPath (VGFont font, VGuint glyphIndex, VGPath path, VGboolean isHinted, const VGfloat * glyphOrigin, const VGfloat * escapement);
void mvgSetGlyphToImage (VGFont font, VGuint glyphIndex, VGImage image, const VGfloat * glyphOrigin, const VGfloat * escapement);
void mvgClearGlyph (VGFont font, VGuint glyphIndex);
void mvgDrawGlyph (VGFont font, VGuint glyphIndex, VGbitfield paintModes, VGboolean allowAutoHinting);
void mvgDrawGlyphs (VGFont font, VGint glyphCount, const VGuint * glyphIndices, const VGfloat * adjustments_x, const VGfloat * adjustments_y, VGbitfield paintModes, VGboolean allowAutoHinting);
void mvgColorMatrix (VGImage dst, VGImage src, const VGfloat * matrix);
void mvgConvolve (VGImage dst, VGImage src, VGint kernelWidth, VGint kernelHeight, VGint shiftX, VGint shiftY, const VGshort * kernel, VGfloat scale, VGfloat bias, VGTilingMode tilingMode);
void mvgSeparableConvolve (VGImage dst, VGImage src, VGint kernelWidth, VGint kernelHeight, VGint shiftX, VGint shiftY, const VGshort * kernelX, const VGshort * kernelY, VGfloat scale, VGfloat bias, VGTilingMode tilingMode);
void mvgGaussianBlur (VGImage dst, VGImage src, VGfloat stdDeviationX, VGfloat stdDeviationY, VGTilingMode tilingMode);
void mvgLookup (VGImage dst, VGImage src, const VGubyte * redLUT, const VGubyte * greenLUT, const VGubyte * blueLUT, const VGubyte * alphaLUT, VGboolean outputLinear, VGboolean outputPremultiplied);
void mvgLookupSingle (VGImage dst, VGImage src, const VGuint * lookupTable, VGImageChannel sourceChannel, VGboolean outputLinear, VGboolean outputPremultiplied);
VGHardwareQueryResult mvgHardwareQuery (VGHardwareQueryType key, VGint setting);
const VGubyte * mvgGetString (VGStringID name);
VGUErrorCode mvguLine (VGPath path, VGfloat x0, VGfloat y0, VGfloat x1, VGfloat y1);
VGUErrorCode mvguPolygon (VGPath path, const VGfloat * points, VGint count, VGboolean closed);
VGUErrorCode mvguRect (VGPath path, VGfloat x, VGfloat y, VGfloat width, VGfloat height);
VGUErrorCode mvguRoundRect (VGPath path, VGfloat x, VGfloat y, VGfloat width, VGfloat height, VGfloat arcWidth, VGfloat arcHeight);
VGUErrorCode mvguEllipse (VGPath path, VGfloat cx, VGfloat cy, VGfloat width, VGfloat height);
VGUErrorCode mvguArc (VGPath path, VGfloat x, VGfloat y, VGfloat width, VGfloat height, VGfloat startAngle, VGfloat angleExtent, VGUArcType arcType);
VGUErrorCode mvguComputeWarpQuadToSquare (VGfloat sx0, VGfloat sy0, VGfloat sx1, VGfloat sy1, VGfloat sx2, VGfloat sy2, VGfloat sx3, VGfloat sy3, VGfloat * matrix);
VGUErrorCode mvguComputeWarpSquareToQuad (VGfloat dx0, VGfloat dy0, VGfloat dx1, VGfloat dy1, VGfloat dx2, VGfloat dy2, VGfloat dx3, VGfloat dy3, VGfloat * matrix);
#endif