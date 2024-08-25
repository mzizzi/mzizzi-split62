taskkill /F /IM pcbnew.exe /T
taskkill /F /IM kicad.exe /T


Remove-Item -Recurse -Force output/

node_modules\.bin\ergogen  .

if ($LASTEXITCODE -ne 0) {
    Write-Host "ergogen command failed with exit code $LASTEXITCODE"
    exit $LASTEXITCODE  # Exit the script with the same error code
}

& "C:\Program Files\KiCad\8.0\bin\pcbnew.exe" "output\pcbs\split62.kicad_pcb"