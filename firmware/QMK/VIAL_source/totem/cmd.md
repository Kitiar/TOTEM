# Commands

## Create Link

```batch
cmd /c mklink /J "%HOMEPATH%\qmk_firmware\keyboards\totem" "%CD%"
```

## Flash 

```batch
qmk flash -kb totem -km kit -bl uf2-split-left
```

```batch
qmk flash -kb totem -km kit -bl uf2-split-right
```
