/* Copyright 2014 Jonas Platte
 *
 * This file is part of Cyvasse Online.
 *
 * Cyvasse Online is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Cyvasse Online is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MIKELEPAGE_RULESET_HPP_
#define _MIKELEPAGE_RULESET_HPP_

#include "rule_set.hpp"

#include <featherkit/rendering/renderer2d.hpp>
#include "boards/hexagonal_board.hpp"
#include "mikelepage/piece.hpp"

using namespace cyvmath::mikelepage;

/** This rule set was created by Michael Le Page (http://www.mikelepage.com/)

    See http://asoiaf.westeros.org/index.php/topic/58545-complete-cyvasse-rules/
 */
class MikelepageRuleSet : public RuleSet
{
	private:
		// non-copyable
		MikelepageRuleSet(const MikelepageRuleSet&) = delete;
		const MikelepageRuleSet& operator= (const MikelepageRuleSet&) = delete;

		class RenderedPiece : public Piece
		{
			private:
				fea::Texture _texture;
				fea::Quad _quad;

			public:
				RenderedPiece(PieceType, PlayersColor);

				fea::Quad& getQuad()
				{
					return _quad;
				}

				operator fea::Quad& ()
				{
					return _quad;
				}
		};

		typedef HexagonalBoard<6> Board;
		typedef std::unordered_map<Board::Coordinate, RenderedPiece*> pieceMap;
		typedef std::vector<RenderedPiece*> pieceVec;

		Board _board;

		const PlayersColor _playersColor;

		// the following variables are arrays because they exist once for each player
		bool _setup;

		// pieces which are active (on the board) can be found by their coordinate
		pieceMap _activePieces[2];
		pieceVec _inactivePieces[2];

		// the dragon is the only piece that can be inactive but alive (after setup)
		bool _dragonAlive[2];

		// the same as both _activePieces maps together
		// for rendering
		pieceVec _allActivePieces;

	public:
		MikelepageRuleSet(fea::Renderer2D&, PlayersColor);

		void tick() override;
		void tickSetup();
		void tickPlaying();
};

#endif // _MIKELEPAGE_RULESET_HPP_
