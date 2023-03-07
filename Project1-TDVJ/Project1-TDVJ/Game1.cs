using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using System.IO;

namespace Project1_TDVJ
{
    public class Game1 : Game
    {
        private GraphicsDeviceManager _graphics;
        private SpriteBatch _spriteBatch;
        private SpriteFont font;
        private int nrLinhas = 0;
        private int nrColunas = 0;
        private char[,] level;
        private Texture2D player, dot, box, wall;
        int tileSize = 64;

        public Game1()
        {
            _graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
            IsMouseVisible = true;
        }

        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
            LoadLevel("level1.txt"); //Carrega o ficheiro "level1.txt"
        }

        protected override void LoadContent()
        {
            _spriteBatch = new SpriteBatch(GraphicsDevice);
            font = Content.Load<SpriteFont>("File");
            player = Content.Load<Texture2D>("Character4");
            dot = Content.Load<Texture2D>("EndPoint_Red");
            box = Content.Load<Texture2D>("Crate_Red");
            wall = Content.Load<Texture2D>("WallRound_Black");

            // TODO: use this.Content to load your game content here
        }

        protected override void Update(GameTime gameTime)
        {
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
                Exit();

            // TODO: Add your update logic here

            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            // TODO: Add your drawing code here

            _spriteBatch.Begin();
            _spriteBatch.DrawString(font, "Ola amigos", new Vector2(0, 0), Color.Black);

            Rectangle position = new Rectangle(0, 0, tileSize, tileSize);
            for (int x = 0; x < level.GetLength(0); x++) //pega a primeira dimensão
            {
                for (int y = 0; y < level.GetLength(1); y++) //pega a segunda dimensão
                {
                    switch (level[x, y])
                    {
                        case 'Y':
                            _spriteBatch.Draw(player, position, Color.White);
                            break;
                        case '#':
                            _spriteBatch.Draw(box, position, Color.White);
                            break;
                        case '.':
                            _spriteBatch.Draw(dot, position, Color.White);
                            break;
                        case 'X':
                            _spriteBatch.Draw(wall, position, Color.White);
                            break;
                    }
                }
            }

            _spriteBatch.End();

            base.Draw(gameTime);
        }

        void LoadLevel(string levelFile)
        {
            string[] linhas = File.ReadAllLines($"Content/{levelFile}");
            nrLinhas = linhas.Length;
            nrColunas = linhas[0].Length;
            level = new char[nrColunas, nrLinhas];

            for(int x = 0; x < nrColunas; x++)
            {
                for(int y = 0; y < nrLinhas; y++)
                {
                    level[x, y] = linhas[y][x];
                }
            }
        }
    }
}