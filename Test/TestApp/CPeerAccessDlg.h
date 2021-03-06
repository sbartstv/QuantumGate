// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#pragma once

#include "CDialogBase.h"

class CPeerAccessDlg : public CDialogBase
{
	DECLARE_DYNAMIC(CPeerAccessDlg)

public:
	CPeerAccessDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPeerAccessDlg();

	void SetAccessManager(QuantumGate::AccessManager* am) noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PEER_ACCESS_DIALOG };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
	afx_msg void OnEnChangeUuid();
	afx_msg void OnCbnSelchangeAccessCombo();
	afx_msg void OnLvnItemchangedPeerList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedAddPeer();
	afx_msg void OnBnClickedRemovePeer();
	afx_msg void OnBnClickedBrowse();
	afx_msg void OnCbnSelChangeDefaultAccessCombo();

private:
	void UpdatePeerList() noexcept;
	void UpdateControls() noexcept;

private:
	QuantumGate::AccessManager* m_AccessManager{ nullptr };
};
