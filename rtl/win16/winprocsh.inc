
function LOBYTE(w: Word): Byte; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function HIBYTE(w: Word): Byte; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function LOWORD(l: LongInt): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function HIWORD(l: LongInt): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELONG(low, high: Word): LONG; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELPARAM(low, high: Word): LPARAM; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function MAKELRESULT(low, high: Word): LRESULT; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELP(sel, off: Word): FarPointer; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function SELECTOROF(lp: FarPointer): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function OFFSETOF(lp: FarPointer): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

// FIELDOFFSET

{ System Information }
function GetVersion: DWORD; external 'KERNEL';

function GetFreeSpace(Flag: UINT): DWORD; external 'KERNEL';
function GetCurrentPDB: UINT; external 'KERNEL';

function GetWindowsDirectory(Buffer: LPSTR; Size: UINT): UINT; external 'KERNEL';
function GetSystemDirectory(Buffer: LPSTR; Size: UINT): UINT; external 'KERNEL';

function GetWinFlags: DWORD; external 'KERNEL';

function GetDOSEnvironment: LPSTR; external 'KERNEL';

function GetCurrentTime: DWORD; external 'USER';
function GetTickCount: DWORD; external 'USER';
function GetTimerResolution: DWORD; external 'USER';

{ Error handling }
procedure FatalExit(Code: SmallInt); external 'KERNEL';
procedure FatalAppExit(Action: UINT; MessageText: LPCSTR); external 'KERNEL';

function ExitWindows(dwReturnCode: DWORD; wReserved: UINT): BOOL; external 'USER';

procedure DebugBreak; external 'KERNEL';
procedure OutputDebugString(OutputString: LPCSTR); external 'KERNEL';

function SetErrorMode(Mode: UINT): UINT; external 'KERNEL';

{ Catch/Throw and stack management }

function Catch(CatchBuf: LPCATCHBUF): SmallInt; external 'KERNEL';
procedure Throw(CatchBuf: LPCATCHBUF; ThrowBack: SmallInt); external 'KERNEL';
{$ifdef VAR_PARAMS_ARE_FAR}
function Catch(var CatchBuf: TCatchBuf): SmallInt; external 'KERNEL';
procedure Throw(var CatchBuf: TCatchBuf; ThrowBack: SmallInt); external 'KERNEL';
{$endif}

procedure SwitchStackBack; external 'KERNEL';
procedure SwitchStackTo(StackSegment, StackPointer, StackTop: UINT); external 'KERNEL';

{ Module Management }

function LoadModule(ModuleName: LPCSTR; ParameterName: LPVOID): HINST; external 'KERNEL';
function FreeModule(Module: HINST): BOOL; external 'KERNEL';

function LoadLibrary(LibFileName: LPCSTR): HINST; external 'KERNEL';
procedure FreeLibrary(LibModule: HINST); external 'KERNEL';

function WinExec(CmdLine: LPCSTR; CmdShow: UINT): UINT; external 'KERNEL';

function GetModuleHandle(ModuleName: LPCSTR): HMODULE; external 'KERNEL';

function GetModuleUsage(Module: HINST): SmallInt; external 'KERNEL';
function GetModuleFileName(Module: HINST; FileName: LPSTR; Size: SmallInt): SmallInt; external 'KERNEL';

function GetProcAddress(Module: HINST; ProcName: LPCSTR): FARPROC; external 'KERNEL';

function GetInstanceData(Instance: HINST; Data: PBYTE; Count: SmallInt): SmallInt; external 'KERNEL';

function GetCodeHandle(Proc: FARPROC): HGLOBAL; external 'KERNEL';

procedure GetCodeInfo(lpProc: FARPROC; lpSegInfo: LPSEGINFO); external 'KERNEL';

function MakeProcInstance(Proc: FARPROC; Instance: HINST): FARPROC; external 'KERNEL';
procedure FreeProcInstance(Proc: FARPROC); external 'KERNEL';

{#ifdef _LAX
#define MakeProcInstance(__F, __H) MakeProcInstance((FARPROC)__F, __H)
#define FreeProcInstance(__F)      FreeProcInstance((FARPROC)__F)
#endif /* _LAX */}

function SetSwapAreaSize(Size: UINT): LONG; external 'KERNEL';
procedure SwapRecording(Flag: UINT); external 'KERNEL';
procedure ValidateCodeSegments; external 'KERNEL';

{ Task Management }

function GetNumTasks: UINT; external 'KERNEL';
function GetCurrentTask: HTASK; external 'KERNEL';

procedure Yield; external 'KERNEL';
procedure DirectedYield(Task: HTASK); external 'KERNEL';

{ Global memory management }

function GlobalDiscard(h: HGLOBAL): HGLOBAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function GlobalAlloc(Flags: UINT; Bytes: DWORD): HGLOBAL; external 'KERNEL';
function GlobalReAlloc(Mem: HGLOBAL; Bytes: DWORD; Flags: UINT): HGLOBAL; external 'KERNEL';
function GlobalFree(Mem: HGLOBAL): HGLOBAL; external 'KERNEL';

function GlobalDosAlloc(Bytes: DWORD): DWORD; external 'KERNEL';
function GlobalDosFree(Selector: UINT): UINT; external 'KERNEL';

function GlobalLock(Mem: HGLOBAL): FarPointer; external 'KERNEL';
function GlobalUnlock(Mem: HGLOBAL): BOOL; external 'KERNEL';

function GlobalSize(Mem: HGLOBAL): DWORD; external 'KERNEL';
function GlobalHandle(Mem: UINT): DWORD; external 'KERNEL';

function GlobalFlags(Mem: HGLOBAL): UINT; external 'KERNEL';

function GlobalWire(Mem: HGLOBAL): FarPointer; external 'KERNEL';
function GlobalUnWire(Mem: HGLOBAL): BOOL; external 'KERNEL';

function GlobalPageLock(Selector: HGLOBAL): UINT; external 'KERNEL';
function GlobalPageUnlock(Selector: HGLOBAL): UINT; external 'KERNEL';

procedure GlobalFix(Mem: HGLOBAL); external 'KERNEL';
procedure GlobalUnfix(Mem: HGLOBAL); external 'KERNEL';

function GlobalLRUNewest(Mem: HGLOBAL): HGLOBAL; external 'KERNEL';
function GlobalLRUOldest(Mem: HGLOBAL): HGLOBAL; external 'KERNEL';

function GlobalCompact(MinFree: DWORD): DWORD; external 'KERNEL';

procedure GlobalNotify(NotifyProc: GNOTIFYPROC); external 'KERNEL';

function LockSegment(Segment: UINT): HGLOBAL; external 'KERNEL';
procedure UnlockSegment(Segment: UINT); external 'KERNEL';

function LockData(dummy: SmallInt): HGLOBAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
procedure UnlockData(dummy: SmallInt); {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function AllocSelector(Selector: UINT): UINT; external 'KERNEL';
function FreeSelector(Selector: UINT): UINT; external 'KERNEL';
function AllocDStoCSAlias(Selector: UINT): UINT; external 'KERNEL';
function PrestoChangoSelector(sourceSel, destSel: UINT): UINT; external 'KERNEL';
function GetSelectorBase(Selector: UINT): DWORD; external 'KERNEL';
function SetSelectorBase(Selector: UINT; Base: DWORD): UINT; external 'KERNEL';
function GetSelectorLimit(Selector: UINT): DWORD; external 'KERNEL';
function SetSelectorLimit(Selector: UINT; Base: DWORD): UINT; external 'KERNEL';

procedure LimitEmsPages(Kbytes: DWORD); external 'KERNEL';

procedure ValidateFreeSpaces; external 'KERNEL';

{ Local Memory Management }

function LocalDiscard(h: HLOCAL): HLOCAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function LocalAlloc(Flags, Bytes: UINT): HLOCAL; external 'KERNEL';
function LocalReAlloc(Mem: HLOCAL; Bytes, Flags: UINT): HLOCAL; external 'KERNEL';
function LocalFree(Mem: HLOCAL): HLOCAL; external 'KERNEL';

function LocalLock(Mem: HLOCAL): NearPointer; external 'KERNEL';
function LocalUnlock(Mem: HLOCAL): BOOL; external 'KERNEL';

function LocalSize(Mem: HLOCAL): UINT; external 'KERNEL';
function LocalHandle(Mem: NearPointer): HLOCAL; external 'KERNEL';

function LocalFlags(Mem: HLOCAL): UINT; external 'KERNEL';

function LocalInit(Segment, Start, EndPos: UINT): BOOL; external 'KERNEL';
function LocalCompact(MinFree: UINT): UINT; external 'KERNEL';
function LocalShrink(Seg: HLOCAL; Size: UINT): UINT; external 'KERNEL';

{ File I/O }

function OpenFile(FileName: LPCSTR; ReOpenBuff: LPOFSTRUCT; Style: UINT): HFILE; external 'KERNEL';
{$ifdef VAR_PARAMS_ARE_FAR}
function OpenFile(FileName: LPCSTR; var ReOpenBuff: TOFStruct; Style: UINT): HFILE; external 'KERNEL';
{$endif}

function _lopen(PathName: LPCSTR; ReadWrite: SmallInt): HFILE; external 'KERNEL';
function _lcreat(PathName: LPCSTR; Attribute: SmallInt): HFILE; external 'KERNEL';

function _lclose(FileHandle: HFILE): HFILE; external 'KERNEL';

function _llseek(FileHandle: HFILE; Offset: LONG; Origin: SmallInt): LONG; external 'KERNEL';

function _lread(FileHandle: HFILE; Buffer: HugePointer; Bytes: UINT): UINT; external 'KERNEL';
function _lread(FileHandle: HFILE; Buffer: FarPointer; Bytes: UINT): UINT; external 'KERNEL';
function _lwrite(FileHandle: HFILE; Buffer: HugePointer; Bytes: UINT): UINT; external 'KERNEL';
function _lwrite(FileHandle: HFILE; Buffer: FarPointer; Bytes: UINT): UINT; external 'KERNEL';

function GetTempFileName(DriveLetter: BYTE; PrefixString: LPCSTR; Unique: UINT; TempFileName: LPSTR): SmallInt; external 'KERNEL';
function GetTempFileName(DriveLetter: Char; PrefixString: LPCSTR; Unique: UINT; TempFileName: LPSTR): SmallInt; external 'KERNEL';
function GetTempDrive(DriveLetter: Char): BYTE; external 'KERNEL';

function GetDriveType(Drive: SmallInt): UINT; external 'KERNEL';

function SetHandleCount(Number: UINT): UINT; external 'KERNEL';

{ Network support }
function WNetAddConnection(lpszNetPath, lpszPassword, lpszLocalName: LPSTR): UINT; external 'USER';
function WNetGetConnection(lpszLocalName, lpszRemoteName: LPSTR; cbBufferSize: LPUINT): UINT; external 'USER';
function WNetCancelConnection(lpszName: LPSTR; tForce: BOOL): UINT; external 'USER';

{ Resource Management }

function FindResource(hInstance: HINST; lpName, lpType: LPCSTR): HRSRC; external 'KERNEL';
function LoadResource(hInstance: HINST; hResInfo: HRSRC): HGLOBAL; external 'KERNEL';
function FreeResource(hResData: HGLOBAL): BOOL; external 'KERNEL';

function LockResource(hResData: HGLOBAL): FarPointer; external 'KERNEL';
function UnlockResource(hResData: HGLOBAL): BOOL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function SizeofResource(hInstance: HINST; hResInfo: HRSRC): DWORD; external 'KERNEL';

function AccessResource(hInstance: HINST; hResInfo: HRSRC): SmallInt; external 'KERNEL';

function AllocResource(hInstance: HINST; hResInfo: HRSRC; dwSize: DWORD): HGLOBAL; external 'KERNEL';

function SetResourceHandler(hInstance: HINST; lpType: LPCSTR; lpLoadFunc: RSRCHDLRPROC): RSRCHDLRPROC; external 'KERNEL';

{ Atom Management }

function InitAtomTable(cTableEntries: SmallInt): BOOL; external 'KERNEL';
function AddAtom(lpszName: LPCSTR): ATOM; external 'KERNEL';
function DeleteAtom(atm: ATOM): ATOM; external 'KERNEL';
function FindAtom(lpszString: LPCSTR): ATOM; external 'KERNEL';
function GetAtomName(atm: ATOM; lpszBuffer: LPSTR; cbBuffer: SmallInt): UINT; external 'KERNEL';
function GlobalAddAtom(lpszString: LPCSTR): ATOM; external 'USER';
function GlobalDeleteAtom(atm: ATOM): ATOM; external 'USER';
function GlobalFindAtom(lpszString: LPCSTR): ATOM; external 'USER';
function GlobalGetAtomName(atom: ATOM; lpszBuffer: LPSTR; cbBuffer: SmallInt): UINT; external 'USER';
function GetAtomHandle(atm: ATOM): HLOCAL; external 'KERNEL';

{ WIN.INI Support }

{ User Profile Routines }
  function GetProfileInt(lpszSection: LPCSTR; lpszEntry: LPCSTR; default: SmallInt): UINT; external 'KERNEL';
  function GetProfileString(lpszSection, lpszEntry, lpszDefault: LPCSTR; lpszReturnBuffer: LPSTR; cbReturnBuffer: SmallInt): SmallInt; external 'KERNEL';
  function WriteProfileString(lpszSection, lpszEntry, lpszString: LPCSTR): BOOL; external 'KERNEL';

  function GetPrivateProfileInt(lpszSection, lpszEntry: LPCSTR; default: SmallInt; lpszFilename: LPCSTR): UINT; external 'KERNEL';
  function GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault: LPCSTR; lpszReturnBuffer: LPSTR; cbReturnBuffer: SmallInt; lpszFilename: LPCSTR): SmallInt; external 'KERNEL';
  function WritePrivateProfileString(lpszSection, lpszEntry, lpszString, lpszFilename: LPCSTR): BOOL; external 'KERNEL';

{ International & Char Translation Support }

procedure AnsiToOem(hpszWindows, hpszOem: PHugeChar); external 'KEYBOARD';
procedure AnsiToOem(hpszWindows, hpszOem: PFarChar); external 'KEYBOARD';
procedure OemToAnsi(hpszOemStr, hpszWindowsStr: PHugeChar); external 'KEYBOARD';
procedure OemToAnsi(hpszOemStr, hpszWindowsStr: PFarChar); external 'KEYBOARD';

procedure AnsiToOemBuff(lpszWindowsStr: LPCSTR; lpszOemStr: LPSTR; cbWindowsStr: UINT); external 'KEYBOARD';
procedure OemToAnsiBuff(lpszOemStr: LPCSTR; lpszWindowsStr: LPSTR; cbOemStr: UINT); external 'KEYBOARD';

function AnsiNext(lpchCurrentChar: LPCSTR): LPSTR; external 'USER';
function AnsiPrev(lpchStart, lpchCurrentChar: LPCSTR): LPSTR; external 'USER';

function AnsiUpper(lpszString: LPSTR): LPSTR; external 'USER';
function AnsiLower(lpsz: LPSTR): LPSTR; external 'USER';

function AnsiUpperBuff(lpszString: LPSTR; cbString: UINT): UINT; external 'USER';
function AnsiLowerBuff(lpszString: LPSTR; cbString: UINT): UINT; external 'USER';


function IsCharAlpha(chTest: char): BOOL; external 'USER';
function IsCharAlphaNumeric(chTest: char): BOOL; external 'USER';
function IsCharUpper(chTest: char): BOOL; external 'USER';
function IsCharLower(chTest: char): BOOL; external 'USER';

function lstrcmp(lpszString1, lpszString2: LPCSTR): SmallInt; external 'USER';
function lstrcmpi(lpszString1, lpszString2: LPCSTR): SmallInt; external 'USER';
function lstrcpy(lpszString1: LPSTR; lpszString2: LPCSTR): LPSTR; external 'KERNEL';
function lstrcat(lpszString1: LPSTR; lpszString2: LPCSTR): LPSTR; external 'KERNEL';
function lstrlen(lpszString: LPCSTR): SmallInt; external 'KERNEL';

function LoadString(hints: HINST; idResrouce: UINT; lpszBuffer: LPSTR; cbBuffer: SmallInt): SmallInt; external 'USER';

{ Keyboard Driver Functions }

function OemKeyScan(uOemChar: UINT): DWORD; external 'KEYBOARD';
function VkKeyScan(uChar: UINT): UINT; external 'KEYBOARD';
function GetKeyboardType(fnKeybInfo: SmallInt): SmallInt; external 'KEYBOARD';
function MapVirtualKey(uKeyCode, fuMapType: UINT): UINT; external 'KEYBOARD';
function GetKBCodePage: SmallInt; external 'KEYBOARD';
function GetKeyNameText(lParam: LONG; lpszBuffer: LPSTR; cbMaxKey: SmallInt): SmallInt; external 'KEYBOARD';
function ToAscii(wVirtKey, wScanCode: UINT; lpKeyState: LPBYTE; lpChar: LPDWORD; wFlags: UINT): SmallInt; external 'KEYBOARD';

{ DC Management }

function CreateDC(lpszDriver, lpszDevice, lpszOutput: LPCSTR; lpvInitData: FarPointer): HDC; external 'GDI';
function CreateIC(lpszDriver, lpszDevice, lpszOutput: LPCSTR; lpvInitData: FarPointer): HDC; external 'GDI';
function CreateCompatibleDC(hdc: HDC): HDC; external 'GDI';

function DeleteDC(hdc: HDC): BOOL; external 'GDI';

function GetDCOrg(hdc: HDC): DWORD; external 'GDI';

function SaveDC(hdc: HDC): SmallInt; external 'GDI';
function RestoreDC(hdc: HDC; nSavedDC: SmallInt): BOOL; external 'GDI';

function SetEnvironment(lpPortName: LPCSTR; lpdev: FarPointer; nCount: UINT): SmallInt; external 'GDI';
function GetEnvironment(lpPortName: LPCSTR; lpdev: FarPointer; nMaxSize: UINT): SmallInt; external 'GDI';

function MulDiv(nMultiplicand, nMultiplier, nDivisor: SmallInt): SmallInt; external 'GDI';

{ Device Capabilities }

function GetDeviceCaps(hdc: HDC; iCapability: SmallInt): SmallInt; external 'GDI';

{ Coordinate transformation support }

function SetMapMode(hdc: HDC; fnMapMode: SmallInt): SmallInt; external 'GDI';
function GetMapMode(hdc: HDC): SmallInt; external 'GDI';

function SetWindowOrg(hdc: HDC; nXOrigin, nYOrigin: SmallInt): DWORD; external 'GDI';
function GetWindowOrg(hdc: HDC): DWORD; external 'GDI';

function SetWindowExt(hdc: HDC; nXExtent, nYExtent: SmallInt): DWORD; external 'GDI';
function GetWindowExt(hdc: HDC): DWORD; external 'GDI';

function OffsetWindowOrg(hdc: HDC; nXOffset, nYOffset: SmallInt): DWORD; external 'GDI';
function ScaleWindowExt(hdc: HDC; nXNum, nXDenom, nYNum, nYDenom: SmallInt): DWORD; external 'GDI';

function SetViewportOrg(hdc: HDC; nXOrigin, nYOrigin: SmallInt): DWORD; external 'GDI';
function GetViewportOrg(hdc: HDC): DWORD; external 'GDI';

function SetViewportExt(hdc: HDC; nXExtent, nYExtent: SmallInt): DWORD; external 'GDI';
function GetViewportExt(hdc: HDC): DWORD; external 'GDI';

function OffsetViewportOrg(hdc: HDC; nXOffset, nYOffset: SmallInt): DWORD; external 'GDI';
function ScaleViewportExt(hdc: HDC; nXNum, nXDenom, nYNum, nYDenom: SmallInt): DWORD; external 'GDI';

function DPtoLP(hdc: HDC; lppt: LPPOINT; cPoints: SmallInt): BOOL; external 'GDI';
function LPtoDP(hdc: HDC; lppt: LPPOINT; cPoints: SmallInt): BOOL; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function DPtoLP(hdc: HDC; var pt; cPoints: SmallInt): BOOL; external 'GDI';
function LPtoDP(hdc: HDC; var pt; cPoints: SmallInt): BOOL; external 'GDI';
{$endif}

{ Color support }

function RGB(cRed, cGreen, cBlue: BYTE): COLORREF; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function GetRValue(rgb: DWORD): BYTE; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function GetGValue(rgb: DWORD): BYTE; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function GetBValue(rgb: DWORD): BYTE; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function GetNearestColor(hdc: HDC; clrref: COLORREF): COLORREF; external 'GDI';

function GetSysColor(nDspElement: SmallInt): COLORREF; external 'USER';
procedure SetSysColors(cDspElements: SmallInt; lpnDspElements: LPINT; lpdwRgbValues: LPCOLORREF); external 'USER';
{$ifdef VAR_PARAMS_ARE_FAR}
procedure SetSysColors(cDspElements: SmallInt; var DspElements; var RgbValues); external 'USER';
{$endif}

{ GDI Object Support }

function GetStockObject(fnObject: SmallInt): HGDIOBJ; external 'GDI';

function IsGDIObject(hgdiobj: HGDIOBJ): BOOL; external 'GDI';

function DeleteObject(hgdiobj: HGDIOBJ): BOOL; external 'GDI';
function SelectObject(hdc: HDC; hgdiobj: HGDIOBJ): HGDIOBJ; external 'GDI';
function GetObject(hgdiobj: HGDIOBJ; cbBuffer: SmallInt; lpvObject: FarPointer): SmallInt; external 'GDI';
function UnrealizeObject(hgdiobj: HGDIOBJ): BOOL; external 'GDI';

function EnumObjects(hdc: HDC; fnObjectType: SmallInt; goenmprc: GOBJENUMPROC; lParam: LPARAM): SmallInt; external 'GDI';
function EnumObjects(hdc: HDC; fnObjectType: SmallInt; goenmprc: FARPROC; lParam: LPARAM): SmallInt; external 'GDI';

{ Pen support }

function CreatePen(fnPenStyle, nWidth: SmallInt; clrref: COLORREF): HPEN; external 'GDI';
function CreatePenIndirect(lplgpn: LPLOGPEN): HPEN; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePenIndirect(var lgpn: LOGPEN): HPEN; external 'GDI';
{$endif}

{ Brush support }

function CreateSolidBrush(clrref: COLORREF): HBRUSH; external 'GDI';
function CreateHatchBrush(fnStyle: SmallInt; clrref: COLORREF): HBRUSH; external 'GDI';
function CreatePatternBrush(hbmp: HBITMAP): HBRUSH; external 'GDI';
function CreateDIBPatternBrush(hglbDIBPacked: HGLOBAL; fnColorSpec: UINT): HBRUSH; external 'GDI';
function CreateBrushIndirect(lplb: LPLOGBRUSH): HBRUSH; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateBrushIndirect(var lb: LOGBRUSH): HBRUSH; external 'GDI';
{$endif}

function SetBrushOrg(hdc: HDC; nXOrg, nYOrg: SmallInt): DWORD; external 'GDI';
function GetBrushOrg(hdc: HDC): DWORD; external 'GDI';

{ Region support }

function CreateRectRgn(nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): HRGN; external 'GDI';
function CreateRectRgnIndirect(lprc: LPRECT): HRGN; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateRectRgnIndirect(var rc: RECT): HRGN; external 'GDI';
{$endif}
function CreateEllipticRgnIndirect(lprc: LPRECT): HRGN; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateEllipticRgnIndirect(var rc: RECT): HRGN; external 'GDI';
{$endif}
function CreateEllipticRgn(nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): HRGN; external 'GDI';
function CreatePolygonRgn(lppt: LPPOINT; cPoints, fnPolyFillMode: SmallInt): HRGN; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePolygonRgn(var pt; cPoints, fnPolyFillMode: SmallInt): HRGN; external 'GDI';
{$endif}
function CreatePolyPolygonRgn(lppt: LPPOINT; lpnPolyCount: LPINT; cIntegers, fnPolyFillMode: SmallInt): HRGN; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePolyPolygonRgn(var pt; var nPolyCount; cIntegers, fnPolyFillMode: SmallInt): HRGN; external 'GDI';
{$endif}
function CreateRoundRectRgn(nLeftRect, nTopRect, nRightRect, nBottomRect, nWidthEllipse, nHeightEllipse: SmallInt): HRGN; external 'GDI';

procedure SetRectRgn(hrgn: HRGN; nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt); external 'GDI';

function CombineRgn(hrgnDest, hrgnSrc1, hrgnSrc2: HRGN; fCombineMode: SmallInt): SmallInt; external 'GDI';

function EqualRgn(hrgnSrc1, hrgnSrc2: HRGN): BOOL; external 'GDI';
function OffsetRgn(hrgn: HRGN; nXOffset, nYOffset: SmallInt): SmallInt; external 'GDI';

function GetRgnBox(hrgn: HRGN; lprc: LPRECT): SmallInt; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function GetRgnBox(hrgn: HRGN; var rc: RECT): SmallInt; external 'GDI';
{$endif}

function RectInRegion(hrgn: HRGN; lprc: LPRECT): BOOL; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function RectInRegion(hrgn: HRGN; var rc: RECT): BOOL; external 'GDI';
{$endif}
function PtInRegion(hrgn: HRGN; nXPos, nYPos: SmallInt): BOOL; external 'GDI';

{ Color palette Support }

function PALETTERGB(cRed, cGreen, cBlue: BYTE): COLORREF; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function PALETTEINDEX(wPaletteIndex: WORD): COLORREF; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function CreatePalette(lplgpl: LPLOGPALETTE): HPALETTE; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePalette(var lgpl: LOGPALETTE): HPALETTE; external 'GDI';
{$endif}

function SelectPalette(hdc: HDC; hpal: HPALETTE; fPalBack: BOOL): HPALETTE; external 'USER';

function RealizePalette(hdc: HDC): UINT; external 'USER';

function UpdateColors(hdc: HDC): SmallInt; external 'GDI';
procedure AnimatePalette(hpal: HPALETTE; iStart, cEntries: UINT; lppe: LPPALETTEENTRY); external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
procedure AnimatePalette(hpal: HPALETTE; iStart, cEntries: UINT; var pe); external 'GDI';
{$endif}

function SetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; lppe: LPPALETTEENTRY): UINT; external 'GDI';
function GetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; lppe: LPPALETTEENTRY): UINT; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function SetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; var pe): UINT; external 'GDI';
function GetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; var pe): UINT; external 'GDI';
{$endif}

function GetNearestPaletteIndex(hpal: HPALETTE; clrref: COLORREF): UINT; external 'GDI';

function ResizePalette(hpal: HPALETTE; cEntries: UINT): BOOL; external 'GDI';

function GetSystemPaletteEntries(hdc: HDC; iStart, cEntries: UINT; lppe: LPPALETTEENTRY): UINT; external 'GDI';
{$ifdef VAR_PARAMS_ARE_FAR}
function GetSystemPaletteEntries(hdc: HDC; iStart, cEntries: UINT; var pe): UINT; external 'GDI';
{$endif}

function GetSystemPaletteUse(hdc: HDC): UINT; external 'GDI';
function SetSystemPaletteUse(hdc: HDC; fuStatic: UINT): UINT; external 'GDI';