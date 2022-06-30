# H1-Mod

<p align="center">
  <img alig src="https://cdn.discordapp.com/attachments/895680402142941194/938488726391242842/splash.png"/>
</p>

An experimental client for Call of Duty Modern Warfare Remastered (version `1.4.814118.0-0.32767`).  
Research for the latest Steam version of the game is on the [develop](https://github.com/h1-mod/h1-mod/tree/develop) branch.

[This project is based on S1x.](https://github.com/XLabsProject/s1x-client)

## Compile from source

- Clone the Git repo. Do NOT download it as ZIP, that won't work.
- Update the submodules and run `premake5 vs2022` or simply use the delivered `generate.bat`.
- Build via solution file in `build\h1-mod.sln`.

### Premake arguments

| Argument                    | Description                                    |
|:----------------------------|:-----------------------------------------------|
| `--copy-to=PATH`            | Optional, copy the EXE to a custom folder after build, define the path here if wanted. |
| `--dev-build`               | Enable development builds of the client. |

## Credits:

- [XLabsProject](https://github.com/XLabsProject) - codebase and iw6x/s1x research
- [quaK](https://github.com/Joelrau) - lots of insight and help
- [fed](https://github.com/fedddddd) - fixed DW/networking, work from [h2-mod](https://github.com/fedddddd/h2-mod)
- [Skull](https://github.com/skkuull) + [mjkzy](https://github.com/mjkzy) - porting code from s1x
- [momo5502](https://github.com/momo5502) - Arxan/Steam research, developer of x labs clients :D

## Disclaimer

This software has been created purely for the purposes of academic research. It is not intended to be used to attack other systems. Project maintainers are not responsible or liable for misuse of the software. Use responsibly.
