
native event_Trigger(...);
native event_SetNotify(int: event);
native event_StopNotify(...);
native event_SetWork(bool: enabled);
native event_DevPrintNum(nInt);
native event_DevPrintStr(szString[]);
native event_DevPrintFloat(fFloat);
native event_TranslateName(string[]);
native event_DelayWork(fTime);

native MeshRes_Load(szApeName[]);
native AudioRes_Load(szAudioName[]);

native AnimRes_Load(...);
native AnimInst_Acquire(...);
native AnimInst_Init(...);
native AnimInst_Release(...);
native AnimInst_GetUnitPos(...);
native AnimInst_Advance(...);

native f32_SetFromInt(value);
native f32_SetFromString(string[]);
native f32_DevPrint(...);

// Return the result.
native f32_Sum(...);
native f32_Difference(...);
native f32_Product(...);
native f32_Quotient(...);
native f32_Sqrt(...);
native f32_Recip(...);
native f32_RecipSqrt(...);
native f32_IsGreater(...);
native f32_IsGreaterEq(...);
native f32_IsLess(...);
native f32_IsLessEq(...);

native s32_RandomRange(...);

native f32_Add(...);
native f32_Subtract(...);
native f32_Multiply(...);
native f32_Divide(...);

native FWM_Acquire(...);
native FWM_Release(...);
native FWM_Find(...);
native FWM_IsValid(...);
native FWM_AddToWorld(...);
native FWM_RemoveFromWorld(...);
native FWM_Init(...);

native FV3Constant_Acquire(...);
native FV3Constant_Release(...);
native FV3Constant_Init(...);

native FV3Linear_Acquire(...);
native FV3Linear_Release(...);
native FV3Linear_Init(...);

native FQuatTwirlY_Acquire(...);
native FQuatTwirlY_Release(...);
native FQuatTwirlY_Init(...);

native FVec3_GetFromPool(...);
native FVec3_DevPrint(...);
native FVec3_SetFromF32(...);
native FVec3_SetNull(...);
native FVec3_SetFromString(...);
native FVec3_MulF32(...);
native FVec3_Dot(...);
native FVec3_Cross(...);
native FVec3_Sum(...);
native FVec3_Diff(...);
native FVec3_Mag(...);
native FVec3_Mag2(...);
native FVec3_Unitize(...);

native FQuatObj_Start(...);
native FQuatObj_Pause(...);
native FQuatObj_End(...);
native FQuatObj_Reset(...);
native FQuatObj_IsDone(...);
native FQuatObj_SetTimePos(...);

