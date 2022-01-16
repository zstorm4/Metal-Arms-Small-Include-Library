/* 
    These .inc files follow Hungarian Notation as seen here https://www.cse.iitk.ac.in/users/dsrkg/cs245/html/Guide.htm
    Any adjustments are expected to follow this formatting
	For the time being we will not assign tags https://github.com/compuphase/pawn/blob/master/doc/Pawn_Language_Guide.pdf pg.65
    String     Prefix: s Suffix: []   // Suffix included because Small has strings are arrays of chars
    Boolean    Prefix: b
    Integer    Prefix: n
    Float      Prefix: f
    For FANG specific data types, we will use these
    Entity     Prefix: h              // Yes this is also handle in Hungarian Notation
    FVec3Obj   Prefix: vec
    FQuatObj   Prefix: q
    CFMtx43A   Prefix: mtx
	Validate this bs later, seems the devs liked to create their own tags
    MeshEntity Prefix: hme
    MeshActor  Prefix: hma
    BTI        Prefix: hbti
    BTR        Prefix: hbtr
    AnimInst   Prefix: hai
    AudioRes   Prefix: har
    Audio      Prefix: haud
    Particle   Prefix: hp
    Bot        Prefix: hbot
    BotActor   Prefix: hact
    Door       Prefix: hd
*/

native E_Find(sEntityName[]);
native E_FindInWorld(sEntityName[]);
native E_FindOutWorld(sEntityName[]);

native E_IsValid(hEntity);
native E_IsNamed(hEntity, sEntityName[]);
native E_IsBot(hEntity);
native E_IsDoor(hEntity);
native E_IsMesh(hEntity);
native E_IsSwitch(hEntity);

native E_EnableTripwire(hEntity, bIsEnabled);

native E_AddToWorld(hEntity);
native E_RemoveFromWorld(hEntity);
native E_IsInWorld(hEntity);
native E_IsTargetable(hEntity);
native E_IsHittable(hEntity);
native E_IsActionable(hEntity);
native E_IsTripwire(hEntity);
native E_SetNormHealth(hEntity, fHealth);
native E_GetNormHealth(hEntity);
native E_SetTargetable(hEntity, bIsTargetable);
native E_SnapToE(hEntityHunter, hEntityTarget);

native E_GetPos(hEntity, vecPos);
native E_TouchOfDeath(hEntity, bSpawnGoodies);
native E_SetDamageable(hEntity, bIsDamagable);
native E_IsDamageable(hEntity);
// blastIntensity between 0 - 1, 1 is normal, >1 bigger explosion
native E_Blast(hEntity, fBlastIntensity);

native E_DistanceBetween(hEntityA, hEntityB);

native E_AlarmNetFind(sAlarmNetName[]);
// Double check second parameter
// Not a fan of how Alarm Nets are being prefixed as entities, leaving as is for now
native E_TurnOnAlarmNet(hAlarmNet, hEntity);
native E_TurnOffAlarmNet(hAlarmNet);
native E_IsAlarmNetOn(hAlarmNet);


native E_SpawnNetFind(sSpawnNetName[]);
native E_TurnOnSpawnNet();
native E_TurnOffSpawnNet();
// Function only uses 1 param but requires 2?
// Also Spawn Nets ARE NOT entities, leaving again
native E_GetSpawnNetDefCon(hSpawnNet, junk);
native E_SetSpawnNetDefCon(hSpawnNet, nDefConLevel);

// These functions might be broken
native E_SetExplodArmor(hEntity, fUnitArmor);
native E_SetFlameArmor(hEntity, fUnitArmor);
native E_SetBulletArmor(hEntity, fUnitArmor);

// Returns a new mesh entity
native ME_Acquire();
// This function might be broken
native ME_Release();
// These functions might not be exposed...
native ME_Find(sMeshEntityName[]);
native ME_IsValid(hMeshEntity);
native ME_AddToWorld(hMeshEntity);
native ME_RemoveFromWorld(hMeshEntity);

native ME_Init1(hMeshEntity, hMesh);
native ME_Init2(hMeshEntity, hMesh, sMtxName[]);
native ME_AnimSelect(hMeshEntity, nAnimIdx);
native ME_SetAnimSpeed(hMeshEntity, fAnimSpeed);
native ME_GetAnimSpeed(hMeshEntity);
native ME_SetAnimClamp(hMeshEntity, bIsAnimClamped);
native ME_EnableAnim(hMeshEntity, bIsEnabled);
native ME_GetUnitAnimPos(hMeshEntity);
native ME_GetAnimPos(hMeshEntity);
native ME_SetUnitAnimPos(hMeshEntity, fUnitAnimPos);
native ME_SetAnimPos(hMeshEntity, fAnimPos);
// Remain awake when player is away from Entity's cell
native ME_SetAlwaysWork(hMeshEntity, bIsAlwaysWork);

native Bot_Find(sBotName[]);

// Do these functions even work?
native Bot_IsValid(hBot);
native Bot_AddToWorld(hBot);
native Bot_RemoveFromWorld(hBot);
native Bot_IsDeadOrDying(hBot);
native Bot_IsDead(hBot);

// Returns only Player 1, this can (and will) cause issues when porting SP maps to Co-op
native Bot_GetPlayer();
// LookAroundChance is value from 0 - 100 that is likelyhood bot will look around
native Bot_JobWait(hBot, nLookAroundChance);
native Bot_JobWaitAndLook(hBot, hLookAtEntity, nLookAroundChance);
// This may be broken, script wants 8 but function takes 9 parameters???
native Bot_JobWander(hBot, fWonderRadius, bStayInRoom, nSpeedPctMin, nSpeedPctMax, nSociable, nCuriosity, nTakeBreakChance);
// nPatrolSpeed is percentage of speed from 0 - 100
// nDirection is either 0 or 1 for clockwise or counterclockwise respectfully
native Bot_JobPatrol(hBot, sPathName[], nPatrolSpeed, nDirection);
native Bot_GoalGotoPos(hBot, vecDestination, nSpeedPercent, nGoToFlags, nReact);
// Not touching this fully yet
native Bot_GotoE(hBot, hEntityDestination, bEventWhenDone, nSpeedPercent, hEntityLookAt, nWhenToStartLook);
native Bot_GotoEO(...);
native Bot_Attack(hAttacker, hAttacked, bEventWhenDone);
native Bot_FacePt(hBot, vecPos, nTrackPercent, nTimeOut, bEventWhenDone);
native Bot_FaceE(hBot, hEntityLookAt, nTrackPercent, nTimeOut, bEventWhenDone);
native Bot_FacePlayer(hBot, hPlayer, nTimeOut, bEventWhenDone);
native Bot_LoadTalk(sBTA[], nNumToAlloc);
native Bot_Talk(hBot, sBTA[], hEntityLookAt, bStopFirst);

native Bot_FollowLeader(hBotFollower, hEntityLeader, bIsFollowing);
native Bot_SetBaseSpeed(hBot, nSpeedPercent);
native Bot_ClrAttackSpecs(hBot, bResetCurrentAttack);
native Bot_SetAttackSpecs( ...);
native Bot_TurnOnPercep(hBot, nPerceptorID);
native Bot_TurnOffPercep(hBot, nPerceptorID);
native Bot_UsePercep(hBot, nPerceptorID);
native Bot_IgnorePercep(hBot, nPerceptorID);
native Bot_IsPercepOn(hBot, nPerceptorID);
native Bot_IsPercepInUse(hBot, nPerceptorID);

native Ai_EnableUnarmedPlayerRule();
native Ai_DisableUnarmedPlayerRule();
native Ai_IsUnarmedPlayerRuleEnabled();
native Ai_CountEnemiesNear(hEntity, hNearbyEntity, fWithinDist);
native Ai_CountFriendsNear(hEntity, hNearbyEntity, fWithinDist);
native Bot_CanSeeBot(hBotSeeker, hBotSeeked);

native Bot_GetAnimPos(...);
native Bot_FreezePlayer(...);
native Bot_UnfreezePlayer(...);

native Bot_AttachAnim(...);
native Bot_DetachAnim(...);
native Bot_MaskUBody(...);
native Bot_MaskLBody(...);

native Bot_LoadAnim(...);
native Bot_PlayAnim(...);

native Bot_TurnAround( ... );
native Bot_IsTurnedAround( ... );
native Bot_SpotLightOn( ... );

native Bot_ZomStartForming( ... );
native Bot_ZomFloatPieces( ... );
native Bot_ZomCollapse( ... );

native Bot_PossessExit(hBot, bCanBeExited);

// nCtrlParam (0 = never, 1 = auto, 2 = onaction)
native Bot_SetBuddyCtrl(hBot, nCtrlParam);

native BotBlink_Acquire();
native BotBlink_Release(hBotGlitch);
native BotBlink_Init1(hBotGlitch, vecPos);
native BotBlink_AbortScope(bIsImmediate);
native BotGlitch_FallDown();

native BTI_AcquireBTI();
native BTI_ReleaseBTI(hBTI);
native BTI_InitBTI(hBTI, hBot, sBotTalkName[]);
native BTI_PlayBTI(hBTI, hBot);
native BTI_IsBTIPlaying(hBTI);
native BTI_SetAudio2D(hBTI);
native BTI_SetAudioRadius(hBTI, fRadius);
native BTI_DuckAudWhenPlay(hBTI, bIsDuckAudio);


native Door_Find(sDoorName[]);
native Door_IsValid(hDoor);
native Door_GotoPos(hDoor, nNewPos);
native Door_GetUnitPos(hDoor);
native Door_GetUnitPosMap(hDoor);
native Door_SetLock(hDoor, bIsLocked);
native Door_SnapToPos(hDoor, nNewPos);

native FV3Points1_Init1(...);
native FV3Points2_Init1(...);



native FQuatSLERP_Init1(...);


native Cam_Init(vecPos, quatPos, fHalfFOV);
native Cam_Activate();
native Cam_Deactivate();
native Cam_Shake(fIntensity, fDuration);

native CamAnim_GetHandle(sCamName[]);
native CamAnim_Start(hCamera);
native CamAnim_StartEx(hCamera, bIsLetterboxed);
native CamAnim_StartEx2(hCamera, bIsLetterboxed, bIsAIDisabled);
native CamAnim_End();

native Timer_Set(fTime);
native Timer_IsDone();
native Timer_AcquireETimer();
native Timer_ReleaseETimer(hETimer);
native Timer_SetETimer(hETimer, fTime);
native Timer_ShowIcon(hETimer);
native Timer_HideIcon();

native HUD_StartCAMsg(...);

native HUD_RadioStartBank(...);
native HUD_RadioStartStrm(...);
native HUD_RadioStop(...);
native HUD_RadioIsPlaying(...);
native HUD_SetMissionText(...);
native HUD_GetMissionIndex(...);

	// GI stands for goodie instance.
	// These operate on the goodie bag as a whole.
native GB_GetNumGIs(...);
native GB_GetProb(...);
native GB_SetProb(...);

	// These operate on specific goodie instances.
native GB_GetGoodieType(...);
native GB_SetGoodieType(...);
native GB_GetGoodieQuant1(...);
native GB_SetGoodieQuant1(...);
native GB_GetGoodieQuant2(...);
native GB_SetGoodieQuant2(...);
native GB_GetGoodieProb(...);
native GB_SetGoodieProb(...);

native Music_Play(sWvsName[]);
native Music_PlayEx(sWvsName[], nVolume, bFadeIn);
// These two are test functions, use Music_Play and Music_PlayEx instead
native Music_PlayDefault();
native Music_PlayDefaultEx(nVolume, bFadeIn);
native Music_Stop();

native StreamingSfx_Play(sSongName[]);
native StreamingSfx_PlayEx(sGoodieName[], nVolume, bFadeIn);	
	
native Speech_Play(...);	
native Speech_Stop(...);	

native Audio_GetSFXHandle(sAudioName[]);
native Audio_SetAmbientSFX(...);
native Audio_GetAmbientSFX(...);
native Audio_SetAmbientVol(...);
native Audio_GetAmbientVol(...);
native Audio_SetAmbientRad(...);
native Audio_GetAmbientRad(...);
native Audio_PlayAmbient(...);
native Audio_StopAmbient(...);
native Audio_Play2DSound(hSFXname, nvolume);

native Movie_GetHandle(sMovieName[]);
native Movie_Play(...);
native Movie_PlayEx(...);
native Movie_Stop(...);

native Particle_Find(...);
native Particle_Start(...);
native Particle_Stop(...);

native Checkpoint_Save();

native DE_StartDestruct(...);


native Game_BeginCutScene(sTitle[]);
native Game_EndCutScene();
// Needs to be tested, supposidly exits level and loads in level defined in parameter?
native Game_WinLevel(sGoToLevel[]);
native Game_DoPauseMode();

native Tack_Find(...);

native Tack_GetHealth(...);
native Tack_SetHealth(...);

native Tack_SetArmorProf(...);

native Tack_Enable(hTack, bIsEnabled);
native Tack_Remove(...);
native Tack_ToEntityStat(...);
native Tack_ToEntityDyn(...);
native Tack_ToPos(...);
native Tack_SetRange(...);

native Tack_IsEnabled(...);
native Tack_GetRangeMin(...);
native Tack_GetRangeMax(...);
native Tack_GetSnapped2Me(...);

native Tack_GetPhysEntity(...);

native Phys_Reset(...);
native Phys_Freeze(...);
native Phys_Kickstart(...);
native Phys_Sleep(...);
native Phys_SetDampening(...);
native Phys_SetPrimeSecs(...);
native Phys_SetGravity(...);

native Phys_IsFrozen(...);
native Phys_IsSleeping(...);
native Phys_GetDampening(...);
native Phys_GetPrimeSecs(...);
native Phys_GetGravity(...);

native Phys_GetTackCount(...);
native Phys_GetTack(...);

native SActor_Init(...);
native SActor_SetTimePos(...);
native SActor_GetTimePos(...);
native SActor_Reset(...);
native SActor_Start(...);
native SActor_Stop(...);
native SActor_IsDone(...);
	//GSActor (General Spline Actor) specific functions
native GSActor_Acquire(...);
	//HSActor (Horizontal Spline Actor) specific functions
native HSActor_Acquire(...);
	//SSActor (Swinging Spline Actor) specific functions
native SSActor_Acquire(...);
	//SOSActor (Static Orientation Spline Actor) specific functions
native SOSActor_Acquire(...);

native Barter_MoveToPoint(sPointName[]);	
native Barter_Remove(bFadeMusic);	
native Barter_SetAttract(nWhichTable, fAttractMusicRadius, fAttractSpeechRadius);	

native Vehicle_SetPath(hVehicle, hSpline);	
native Vehicle_ClearPath(hVehicle);	
native Vehicle_SetPlayer(hVehicle, hPlayer);	
native Vehicle_PlayerDrive(hVehicle, bIsDrivable);	
native Vehicle_Driveable(hVehicle, bIsDrivable);	
// nSpeedPercent is percentage from 0 - 100
native Vehicle_MaxSpeed(hVehicle, nSpeedPercent);	
native Vehicle_PlayerGun(hVehicle, hPlayer);	
native Vehicle_EjectDriver(hVehicle);	
native Vehicle_EjectGunner(hVehicle);	
native Vehicle_GetSpeed(hVehicle);	
native Vehicle_DriverExit(hVehicle, bCanExit);	
native Vehicle_GunnerExit(hVehicle, bCanExit);	

native FX_Explosion_Find(sExplosionName[]);	
native FX_Explosion(hExplosion, hEntity);	

native G_GiveToGlitch(sGoodieName[]);	
native G_NotifyGoodieUsed(sGoodieName[]);	
native G_IsInInventory(sGoodieName[]);	

native Deb_RumbleShake(hEntity, bEnableRumbleShake);	
native Deb_GetRumbleShake(hEntity);	
native Deb_SetAutoShake(hEntity, fAutoShakeSecondsMin, fAutoShakeSecondsMax);	
native Deb_Shake(hEntity, fIntensity);	

native MeshActor_Acquire();
native MeshActor_Release(hMeshActor);
native MeshActor_IsValid(hMeshActor);
native MeshActor_Init(hMeshActor, hMeshEntity, vecPost, vecQuat);
native MeshActor_Activate(hMeshActor);
native MeshActor_Deactivat(hMeshActor);
native MeshActor_SetPosObj(hMeshActor, vecPos);
native MeshActor_SetQuatObj(hMeshActor, quatPos);
native BotActor_Acquire();
native BotActor_Release(hBotActor);
native BotActor_IsValid(hBotActor);
native BotActor_Init1(hBotActor, hBot);
native BotActor_Init2(hBotActor, hBot, hAnimInst, nAnimSlot);
native BotActor_Activate(hBotActor);
native BotActor_Deactivate(hBotActor);
native BotActor_SetPosObj(hBotActor, vecPos);
native BotActor_SetQuatObj(hBotActor, quatPos);
native BotActor_SetAnimMult(hBotActor, fAnimMult);
// ??? Are these ever called?
native CamActor_Acquire(...);
native CamActor_Release(...);
native CamActor_IsValid(...);
native CamActor_Init(...);
native CamActor_Activate(...);
native CamActor_Deactivate(...);
native CamActor_SetPosObj(...);
native CamActor_SetQuatObj(...);

