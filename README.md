>[!WARNING]
> `Bedrock.Desktop` has been deprecated in favor of [Stonecutter](https://github.com/Aetopia/Stonecutter).

# Bedrock.Desktop
Prevent Minecraft: Bedrock Edition from suspending.

## Usage
- Run the following script in PowerShell to add Bedrock.Desktop to startup:

    ```powershell
    $ProgressPreference = "SilentlyContinue"
    $Path = [System.Environment]::GetFolderPath("Startup", "Create")
    Invoke-RestMethod "https://github.com/Aetopia/Bedrock.Desktop/releases/latest/download/Bedrock.Desktop.exe" -OutFile "$Path\Bedrock.Desktop.exe"
    & "$Path\Bedrock.Desktop.exe"
    $ProgressPreference = "Continue"
    ```
> [!IMPORTANT]
> - The fix persists even when Minecraft: Bedrock Edition is updated.
> - The fix only applies if Minecraft or Minecraft Preview is installed.
> - The fix only remains active until you sign out.

# Build
1. Install [MSYS2](https://www.msys2.org/) & [UPX](https://upx.github.io/) for optional compression.
2. Update the MSYS2 Environment until there are no pending updates using:

    ```bash
    pacman -Syu --noconfirm
    ```

3. Install GCC i686 using:

    ```bash
    pacman -S mingw-w64-i686-gcc --noconfirm
    ```

4. Make sure `<MSYS2 Installation Directory>\mingw32\bin` is added to the Windows `PATH` environment variable.
5. Run [`Build.cmd`](Build.cmd).
